#ifndef USTAR_RECOVERY_BEHAVIOR_H
#define USTAR_RECOVERY_BEHAVIOR_H

#include <costmap/costmap_ros/costmap_2d_ros.h>
#include <tf2_ros/buffer.h>

namespace UstarPlanning
{
  /**
   * @class RecoveryBehavior
   * @brief Provides an interface for recovery behaviors used in navigation. All recovery behaviors written as plugins for the navigation stack must adhere to this interface.
   */
  class RecoveryBehavior
  {
  public:
    /**
       * @brief  Initialization function for the RecoveryBehavior
       * @param tf A pointer to a transform listener
       * @param global_costmap A pointer to the global_costmap used by the navigation stack 
       * @param local_costmap A pointer to the local_costmap used by the navigation stack 
       */
    virtual void initialize(std::string name, tf2_ros::Buffer *tf, UstarCostmap::Costmap2DROS *global_costmap, UstarCostmap::Costmap2DROS *local_costmap) = 0;

    /**
       * @brief   Runs the RecoveryBehavior
       */
    virtual void runBehavior() = 0;

    /**
       * @brief  Virtual destructor for the interface
       */
    virtual ~RecoveryBehavior() {}

  protected:
    RecoveryBehavior() {}
  };
}; // namespace UstarPlanning

#endif // NAV_CORE_RECOVERY_BEHAVIOR_H
