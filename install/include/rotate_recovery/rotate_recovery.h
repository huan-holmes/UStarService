
#ifndef ROTATE_RECOVERY_ROTATE_RECOVERY_H
#define ROTATE_RECOVERY_ROTATE_RECOVERY_H
#include <nav_core/recovery_behavior.h>
#include <costmap/costmap_ros/costmap_2d_ros.h>
#include <tf2_ros/buffer.h>
#include <base_local_planner/costmap_model.h>
#include <string>

namespace rotate_recovery
{
/**
 * @class RotateRecovery
 * @brief A recovery behavior that rotates the robot in-place to attempt to clear out space
 */
class RotateRecovery : public UstarPlanning::RecoveryBehavior
{
public:
  /**
   * @brief  Constructor, make sure to call initialize in addition to actually initialize the object
   */
  RotateRecovery();

  /**
   * @brief  Initialization function for the RotateRecovery recovery behavior
   * @param name Namespace used in initialization
   * @param tf (unused)
   * @param global_costmap (unused)
   * @param local_costmap A pointer to the local_costmap used by the navigation stack
   */
  void initialize(std::string name, tf2_ros::Buffer*,
                  UstarCostmap::Costmap2DROS*, UstarCostmap::Costmap2DROS* local_costmap);

  /**
   * @brief  Run the RotateRecovery recovery behavior.
   */
  void runBehavior();

  /**
   * @brief  Destructor for the rotate recovery behavior
   */
  ~RotateRecovery();

private:
  UstarCostmap::Costmap2DROS* local_costmap_;
  bool initialized_;
  double sim_granularity_, min_rotational_vel_, max_rotational_vel_, acc_lim_th_, tolerance_, frequency_;
  base_local_planner::CostmapModel* world_model_;
};
};  // namespace rotate_recovery
#endif  // ROTATE_RECOVERY_ROTATE_RECOVERY_H
