#ifndef COSTMAP_2D_STATIC_LAYER_H_
#define COSTMAP_2D_STATIC_LAYER_H_

#include <ros/ros.h>
#include "costmap/layers/costmap_layer.h"
#include "costmap/costmap_ros/layered_costmap.h"
#include "costmap/GenericPluginConfig.h"
#include <dynamic_reconfigure/server.h>
#include <nav_msgs/OccupancyGrid.h>
#include <map_msgs/OccupancyGridUpdate.h>
#include <message_filters/subscriber.h>

namespace UstarCostmap
{

  class StaticLayer : public CostmapLayer
  {
    public:
      StaticLayer();
      virtual ~StaticLayer();
      virtual void onInitialize();
      virtual void activate();
      virtual void deactivate();
      virtual void reset();

      virtual void updateBounds(double robot_x, double robot_y, double robot_yaw, double *min_x, double *min_y,
                              double *max_x, double *max_y);
      virtual void updateCosts(UstarCostmap::Costmap2D &master_grid, int min_i, int min_j, int max_i, int max_j);

      virtual void matchSize();

    private:
      /**
       * @brief  Callback to update the costmap's map from the map_server
       * @param new_map The map to put into the costmap. The origin of the new
       * map along with its size will determine what parts of the costmap's
       * static map are overwritten.
       */
      void incomingMap(const nav_msgs::OccupancyGridConstPtr &new_map);
      void incomingUpdate(const map_msgs::OccupancyGridUpdateConstPtr &update);
      void reconfigureCB(UstarCostmap::GenericPluginConfig &config, uint32_t level);

      unsigned char interpretValue(unsigned char value);

      std::string global_frame_; ///< @brief The global frame for the costmap
      std::string map_frame_;    /// @brief frame that map is located in
      bool subscribe_to_updates_;
      bool map_received_;
      bool has_updated_data_; 
      unsigned int x_, y_, width_, height_;
      bool track_unknown_space_;
      bool use_maximum_;
      bool first_map_only_; ///< @brief Store the first static map and reuse it on reinitializing
      bool trinary_costmap_;
      ros::Subscriber map_sub_, map_update_sub_;

      unsigned char lethal_threshold_, unknown_cost_value_;

      dynamic_reconfigure::Server<UstarCostmap::GenericPluginConfig> *dsrv_;
  };

} // namespace UstarCostmap

#endif // COSTMAP_2D_STATIC_LAYER_H_
