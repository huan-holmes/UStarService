#include "costmap/layers/simulator_layer.h"
#include <pluginlib/class_list_macros.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

PLUGINLIB_EXPORT_CLASS(UstarCostmap::SimulatorLayer, UstarCostmap::Layer)

using UstarCostmap::LETHAL_OBSTACLE;

namespace UstarCostmap
{

    SimulatorLayer::SimulatorLayer() {}

    void SimulatorLayer::onInitialize()
    {
        ros::NodeHandle nh("~/" + name_);
        current_ = true;
        rolling_window_ = layered_costmap_->isRolling();
        global_frame_ = layered_costmap_->getGlobalFrameID();
        sub_ = nh_.subscribe("visualization_marker_array", 10, &SimulatorLayer::obstacleArrayCallback, this);
        dsrv_ = new dynamic_reconfigure::Server<UstarCostmap::SimulatorPluginConfig>(nh);
        dynamic_reconfigure::Server<UstarCostmap::SimulatorPluginConfig>::CallbackType cb = boost::bind(
            &SimulatorLayer::reconfigureCB, this, _1, _2);
        dsrv_->setCallback(cb);
    }

    void SimulatorLayer::reconfigureCB(UstarCostmap::SimulatorPluginConfig &config, uint32_t level)
    {
        enabled_ = config.enabled;
    }
    void SimulatorLayer::obstacleArrayCallback(const visualization_msgs::MarkerArray::ConstPtr &msg)
    {
        marker_array_.markers.clear();
        for (int i = 0; i < msg->markers.size(); i++)
        {
            marker_array_.markers.push_back(msg->markers[i]);
        }
    }
    void SimulatorLayer::updateBounds(double robot_x, double robot_y, double robot_yaw, double *min_x,
                                      double *min_y, double *max_x, double *max_y)
    {
        if (rolling_window_)
            updateOrigin(robot_x - getSizeInMetersX() / 2, robot_y - getSizeInMetersY() / 2);
        if (!enabled_)
            return;

        mark_x_ = *min_x;
        mark_y_ = *min_x;

        *min_x = std::min(*min_x, mark_x_);
        *min_y = std::min(*min_y, mark_y_);
        *max_x = std::max(*max_x, mark_x_);
        *max_y = std::max(*max_y, mark_y_);
    }

    void SimulatorLayer::updateCosts(UstarCostmap::Costmap2D &master_grid, int min_i, int min_j, int max_i,
                                     int max_j)
    {
        if (!enabled_)
            return;
        for (int i = 0; i < marker_array_.markers.size(); i++)
        {
            geometry_msgs::PoseStamped new_pose;
            geometry_msgs::PoseStamped obstacle_pose;
            obstacle_pose.header = marker_array_.markers[i].header;
            obstacle_pose.pose = marker_array_.markers[i].pose;
            try
            {

                tf_->transform(obstacle_pose, new_pose, global_frame_);
                //ROS_INFO_STREAM(global_frame_);
            }
            catch (tf2::LookupException &ex)
            {
                ROS_ERROR_THROTTLE(1.0, "No Transform available Error looking up robot pose: %s\n", ex.what());
                return;
            }
            ROS_INFO_STREAM(new_pose);
            unsigned int mx;
            unsigned int my;
            master_grid.worldToMap(new_pose.pose.position.x, new_pose.pose.position.y, mx, my);
            master_grid.setCost(mx, my, LETHAL_OBSTACLE);   
        }
        
    
    }

} // namespace UstarCostmap