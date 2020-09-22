#include <pcl/io/pcd_io.h>
#include <pcl/segmentation/extract_clusters.h>
#include <jsk_recognition_msgs/BoundingBoxArray.h>

#include <iostream>
#include "radar_process/filter.h"
#define MIN_CLUSTER_SIZE 5
#define MAX_CLUSTER_SIZE 60
namespace UstarFusion
{

    LaserFilter::LaserFilter() : curve_flag_(false)
    {

    }

    void LaserFilter::startFilter()
    {
        //scan_sub_ = nh_.subscribe<sensor_msgs::LaserScan> ("/scan", 100, &LaserFilter::scanCallback, this);

        //订阅　"/scan"
        scan_sub_ = nh_.subscribe<sensor_msgs::LaserScan>("/scan", 10, &LaserFilter::scanCallback_2, this);

        //发布LaserScan转换为PointCloud2的后的数据
        point_cloud_pub_ = nh_.advertise<sensor_msgs::PointCloud2>("/cloud2", 10, false);
        box_array_pub_ = nh_.advertise<jsk_recognition_msgs::BoundingBoxArray>("/detected_bounding_boxs", 10, false);
        //boundingBox_pub_ = nh_.advertise<jsk_recognition_msgs::BoundingBox>("/bounding_boxs", 10, false);
        //此处的tf是 laser_geometry 要用到的
        tfListener_.setExtrapolationLimit(ros::Duration(0.1));

        //前面提到的通过订阅PointCloud2，直接转化为pcl::PointCloud的方式
        pclCloud_sub_ = nh_.subscribe<pcl::PointCloud<pcl::PointXYZ> >("/cloud2", 10, &LaserFilter::pclCloudCallback, this);
    }

    void LaserFilter::scanCallback(const sensor_msgs::LaserScan::ConstPtr &scan)
    {
        sensor_msgs::PointCloud2 cloud;
        projector_.transformLaserScanToPointCloud("laser", *scan, cloud, tfListener_);
        point_cloud_pub_.publish(cloud);
    }

    void LaserFilter::scanCallback_2(const sensor_msgs::LaserScan::ConstPtr &scan)
    {
        sensor_msgs::PointCloud2 cloud;

        /*laser_geometry包中函数，将 sensor_msgs::LaserScan 转换为 sensor_msgs::PointCloud2 */
        //普通转换
        //projector_.projectLaser(*scan, cloud);
        //使用tf的转换
        projector_.transformLaserScanToPointCloud("laser", *scan, cloud, tfListener_);

        int row_step = cloud.row_step;
        int height = cloud.height;

        /*将 sensor_msgs::PointCloud2 转换为　pcl::PointCloud<T> */
        //注意要用fromROSMsg函数需要引入pcl_versions（见头文件定义）
        pcl::PointCloud<pcl::PointXYZ> rawCloud;
        pcl::fromROSMsg(cloud, rawCloud);

        for (size_t i = 0; i < rawCloud.points.size(); i++)
        {
            //std::cout << rawCloud.points[i].x << "\t" << rawCloud.points[i].y << "\t" << rawCloud.points[i].z << std::endl;
        }

        point_cloud_pub_.publish(cloud);
    }

    void LaserFilter::pclCloudCallback1(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr &cloud)
    {
        // for (size_t i = 0; i < cloud->points.size(); i++)
        // {
        //     std::cout << "direct_trans: " << cloud->points[i].x << "\t" << cloud->points[i].y << "\t" << cloud->points[i].z << std::endl;
        // }
        // 申明存储点云的对象.
        // pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_raw(new pcl::PointCloud<pcl::PointXYZ>);

        // 读取一个PCD文件
        // if (pcl::io::loadPCDFile<pcl::PointXYZ>(argv[1], *cloud) != 0)
        // {
        //     return -1;
        // }

        // 建立kd-tree对象用来搜索 .
        pcl::search::KdTree<pcl::PointXYZ>::Ptr kdtree(new pcl::search::KdTree<pcl::PointXYZ>);
        kdtree->setInputCloud(cloud);

        // Euclidean 聚类对象.
        pcl::EuclideanClusterExtraction<pcl::PointXYZ> clustering;
        // 设置聚类的最小值 2cm (small values may cause objects to be divided
        // in several clusters, whereas big values may join objects in a same cluster).
        clustering.setClusterTolerance(0.02);
        // 设置聚类的小点数和最大点云数
        clustering.setMinClusterSize(100);
        clustering.setMaxClusterSize(25000);
        clustering.setSearchMethod(kdtree);
        clustering.setInputCloud(cloud);
        std::vector<pcl::PointIndices> clusters;
        clustering.extract(clusters);

        // For every cluster...
        int currentClusterNum = 1;
        for (std::vector<pcl::PointIndices>::const_iterator i = clusters.begin(); i != clusters.end(); ++i)
        {
            //添加所有的点云到一个新的点云中
            pcl::PointCloud<pcl::PointXYZ>::Ptr cluster(new pcl::PointCloud<pcl::PointXYZ>);
            for (std::vector<int>::const_iterator point = i->indices.begin(); point != i->indices.end(); point++)
                cluster->points.push_back(cloud->points[*point]);
            cluster->width = cluster->points.size();
            cluster->height = 1;
            cluster->is_dense = true;

            // 保存
            if (cluster->points.size() <= 0)
                break;
            std::cout << "Cluster " << currentClusterNum << " has " << cluster->points.size() << " points." << std::endl;
            std::string fileName = "/home/boocax/UstarService/src/fusion/radar_process/launch/cluster" + boost::to_string(currentClusterNum) + ".pcd";
            pcl::io::savePCDFileASCII(fileName, *cluster);

            currentClusterNum++;
        }
    }
    void LaserFilter::pclCloudCallback(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr &cloud)
    {
        double in_max_cluster_distance = 0.2;
        std::vector<Detected_Obj> obj_list;
        clusterSegment(cloud, in_max_cluster_distance, obj_list);
        jsk_recognition_msgs::BoundingBoxArray bbox_array;

        for (size_t i = 0; i < obj_list.size(); i++)
        {
            bbox_array.boxes.push_back(obj_list[i].bounding_box_);
        }
        bbox_array.header.frame_id = "laser";

        box_array_pub_.publish(bbox_array);
    }
    void LaserFilter::clusterSegment(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr &in_pc, double in_max_cluster_distance, std::vector<Detected_Obj> &obj_list)
    {
        //ROS_INFO_STREAM("----clusterSegment()----");
        pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>);

        //create 2d pc
        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_2d(new pcl::PointCloud<pcl::PointXYZ>);
        pcl::copyPointCloud(*in_pc, *cloud_2d);
        //make it flat
        for (size_t i = 0; i < cloud_2d->points.size(); i++)
        {
            cloud_2d->points[i].z = 0;
            // ROS_INFO_STREAM(cloud_2d->points[i].x);
        }

        if (cloud_2d->points.size() > 0)
            tree->setInputCloud(cloud_2d);

        std::vector<pcl::PointIndices> local_indices;

        pcl::EuclideanClusterExtraction<pcl::PointXYZ> euclid;
        euclid.setInputCloud(cloud_2d);
        euclid.setClusterTolerance(in_max_cluster_distance);
        euclid.setMinClusterSize(MIN_CLUSTER_SIZE);
        euclid.setMaxClusterSize(MAX_CLUSTER_SIZE);
        euclid.setSearchMethod(tree);
        euclid.extract(local_indices);
        //ROS_INFO_STREAM(local_indices.size());
        for (size_t i = 0; i < local_indices.size(); i++)
        {
            curve_flag_ = false;
            // the structure to save one detected object
            Detected_Obj obj_info;

            float min_x = std::numeric_limits<float>::max();
            float max_x = -std::numeric_limits<float>::max();
            float min_y = std::numeric_limits<float>::max();
            float max_y = -std::numeric_limits<float>::max();
            float min_z = std::numeric_limits<float>::max();
            float max_z = -std::numeric_limits<float>::max();

            // for (std::vector<pcl::PointIndices>::const_iterator pit = local_indices.begin(); pit != local_indices.end(); ++pit)
            // {

            for (std::vector<int>::const_iterator point = local_indices[i].indices.begin(); point != local_indices[i].indices.end(); point++)
            {
                //fill new colored cluster point by point
                pcl::PointXYZ p;
                p.x = in_pc->points[*point].x;
                p.y = in_pc->points[*point].y;
                p.z = in_pc->points[*point].z;
                obj_info.centroid_.x += p.x;
                obj_info.centroid_.y += p.y;
                obj_info.centroid_.z += p.z;

                if (p.x < min_x)
                    min_x = p.x;
                if (p.y < min_y)
                    min_y = p.y;
                if (p.z < min_z)
                    min_z = p.z;
                if (p.x > max_x)
                    max_x = p.x;
                if (p.y > max_y)
                    max_y = p.y;
                if (p.z > max_z)
                    max_z = p.z;
                // if (!curve_flag_)
                // {
                //     double dist;
                //     dist = point2Line(min_x, min_y, max_x, max_y, p);
                //     if ( dist > 1)
                //         curve_flag_ = true;
                // }
            }
            //}
            // if (!curve_flag_ && checkStaticObstacle(min_x, min_y, max_x, max_y, local_indices[i], in_pc))
            //     continue;
            if(checkStaticObstacle(min_x, min_y, max_x, max_y, local_indices[i], in_pc))
                continue;
            //min, max points
            obj_info.min_point_.x = min_x;
            obj_info.min_point_.y = min_y;
            obj_info.min_point_.z = min_z;

            obj_info.max_point_.x = max_x;
            obj_info.max_point_.y = max_y;
            obj_info.max_point_.z = max_z;

            //calculate centroid
            if (local_indices[i].indices.size() > 0)
            {
                obj_info.centroid_.x /= local_indices[i].indices.size();
                obj_info.centroid_.y /= local_indices[i].indices.size();
                obj_info.centroid_.z /= local_indices[i].indices.size();
            }

            //calculate bounding box
            double length_ = obj_info.max_point_.x - obj_info.min_point_.x;
            double width_ = obj_info.max_point_.y - obj_info.min_point_.y;
            double height_ = obj_info.max_point_.z - obj_info.min_point_.z;

            obj_info.bounding_box_.header.frame_id = "laser";

            obj_info.bounding_box_.pose.position.x = obj_info.min_point_.x + length_ / 2;
            obj_info.bounding_box_.pose.position.y = obj_info.min_point_.y + width_ / 2;
            obj_info.bounding_box_.pose.position.z = obj_info.min_point_.z + height_ / 2;

            // obj_info.bounding_box_.pose.position.x = obj_info.centroid_.x;
            // obj_info.bounding_box_.pose.position.y = obj_info.centroid_.x;
            // obj_info.bounding_box_.pose.position.z = 2;

            obj_info.bounding_box_.dimensions.x = ((length_ < 0) ? -1 * length_ : length_);
            obj_info.bounding_box_.dimensions.y = ((width_ < 0) ? -1 * width_ : width_);
            // obj_info.bounding_box_.dimensions.z = ((height_ < 0) ? -1 * height_ : height_);
            obj_info.bounding_box_.dimensions.z = 2;
            //boundingBox_pub_.publish(obj_info.bounding_box_);
            obj_list.push_back(obj_info);
        }
    }
    bool LaserFilter::checkStaticObstacle(float min_x, float min_y, float max_x, float max_y, pcl::PointIndices local_indice, const pcl::PointCloud<pcl::PointXYZ>::ConstPtr &in_pc)
    {
        double dist;
        pcl::PointXYZ p;
        double max_dist = 0;
        for (std::vector<int>::const_iterator point = local_indice.indices.begin(); point != local_indice.indices.end(); point++)
        {
            p.x = in_pc->points[*point].x;
            p.y = in_pc->points[*point].y;
            p.z = in_pc->points[*point].z;
            dist = point2Line(min_x, min_y, max_x, max_y, p);
            if (max_dist < dist)
                max_dist = dist;
           
        }
        if (max_dist < 0.5 || max_dist > 2.5)
        {
            return true;
        }
        ROS_INFO_STREAM(max_dist);
        return false;
    }
    double LaserFilter::point2Line(float min_x, float min_y, float max_x, float max_y, pcl::PointXYZ point)
    {
        double dist;
        double A, B, C;
        A = -(max_y - min_y) / (max_x - min_x);
        B = -1;
        C = -A * min_x - min_y;
        dist = abs(A * point.x + B * point.y + C) / sqrt(A * A + B * B);
        
        return dist;
    }
} // namespace UstarFusion