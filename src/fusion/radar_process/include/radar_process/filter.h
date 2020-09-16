#include <iostream>

#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <laser_geometry/laser_geometry.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/LaserScan.h>
#include <jsk_recognition_msgs/BoundingBox.h>

#include <pcl_conversions/pcl_conversions.h>
#include <pcl_ros/point_cloud.h>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>

namespace UstarFusion
{

    struct Detected_Obj
    {
        jsk_recognition_msgs::BoundingBox bounding_box_;

        pcl::PointXYZ min_point_;
        pcl::PointXYZ max_point_;
        pcl::PointXYZ centroid_;
    };
    class LaserFilter
    {
    public:
        LaserFilter();

        void startFilter();
        //订阅 LaserScan　数据，并发布 PointCloud2 点云
        void scanCallback(const sensor_msgs::LaserScan::ConstPtr &scan);

        //订阅 LaserScan 数据，先转换为 PointCloud2，再转换为 pcl::PointCloud
        void scanCallback_2(const sensor_msgs::LaserScan::ConstPtr &scan);

        //直接订阅 PointCloud2 然后自动转换为 pcl::PointCloud
        void pclCloudCallback(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr &cloud);
        void pclCloudCallback1(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr &cloud);
        void clusterSegment(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr &in_pc, double in_max_cluster_distance, std::vector<Detected_Obj> &obj_list);

    private : ros::NodeHandle nh_;
        laser_geometry::LaserProjection projector_;
        tf::TransformListener tfListener_;

        //发布　"PointCloud2"
        ros::Publisher point_cloud_publisher_;
        ros::Publisher pub_bounding_boxs_;
        //订阅 "/scan"
        ros::Subscriber scan_sub_;

        //订阅 "/cloud2" -> "PointCloud2"
        ros::Subscriber pclCloud_sub_;
    };
} // namespace UstarFusion