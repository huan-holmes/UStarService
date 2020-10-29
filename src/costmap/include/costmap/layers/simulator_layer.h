#ifndef _SIMULATOR_LAYER_H_
#define _SIMULATOR_LAYER_H_
#include <ros/ros.h>
#include "costmap/layers/costmap_layer.h"
#include <costmap/costmap_ros/layered_costmap.h>
#include <costmap/SimulatorPluginConfig.h>
#include <dynamic_reconfigure/server.h>
#include <visualization_msgs/MarkerArray.h>
namespace UstarCostmap
{

    class SimulatorLayer : public CostmapLayer
    {
    public:
        SimulatorLayer();

        virtual void onInitialize();
        virtual void updateBounds(double origin_x, double origin_y, double origin_yaw, double *min_x, double *min_y, double *max_x,
                                  double *max_y);
        virtual void updateCosts(UstarCostmap::Costmap2D &master_grid, int min_i, int min_j, int max_i, int max_j);
        void obstacleArrayCallback(const visualization_msgs::MarkerArray::ConstPtr& msg);
    private:
        void reconfigureCB(UstarCostmap::SimulatorPluginConfig &config, uint32_t level);

        double mark_x_, mark_y_;
        dynamic_reconfigure::Server<UstarCostmap::SimulatorPluginConfig> *dsrv_;
    
        ros::NodeHandle nh_;
        ros::Subscriber sub_;
        visualization_msgs::MarkerArray marker_array_;
        bool rolling_window_;
        std::string global_frame_;
    };
} // namespace UstarCostmap
#endif