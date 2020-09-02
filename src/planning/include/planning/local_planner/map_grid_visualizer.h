
#ifndef MAP_GRID_VISUALIZER_H_
#define MAP_GRID_VISUALIZER_H_

#include <ros/ros.h>
#include <planning/local_planner/map_grid.h>
#include <costmap/costmap_2d/costmap_2d.h>

namespace base_local_planner {
    class MapGridVisualizer {
        public:
            /**
              * @brief Default constructor
              */
            MapGridVisualizer();

            /**
              * @brief Initializes the MapGridVisualizer
              * @param name The name to be appended to ~/ in order to get the proper namespace for parameters
              * @param costmap The costmap instance to use to get the size of the map to generate a point cloud for
              * @param cost_function The function to use to compute the cost values to be inserted into each point in the output PointCloud as well as whether to include a given point or not
              */
            void initialize(const std::string& name, std::string frame, boost::function<bool (int cx, int cy, float &path_cost, float &goal_cost, float &occ_cost, float &total_cost)> cost_function);

            /**
              * @brief Build and publish a PointCloud if the publish_cost_grid_pc parameter was true. Only include points for which the cost_function at (cx,cy) returns true.
              */
            void publishCostCloud(const UstarCostmap::Costmap2D* costmap_p_);

        private:
            std::string name_; ///< @brief The name to get parameters relative to.
            boost::function<bool (int cx, int cy, float &path_cost, float &goal_cost, float &occ_cost, float &total_cost)> cost_function_; ///< @brief The function to be used to generate the cost components for the output PointCloud
            ros::NodeHandle ns_nh_;
            std::string frame_id_;
            ros::Publisher pub_;
    };
};

#endif
