#ifndef OSCILLATION_COST_FUNCTION_H_
#define OSCILLATION_COST_FUNCTION_H_

#include <base_local_planner/trajectory_cost_function.h>
#include <Eigen/Core>

namespace base_local_planner {

class OscillationCostFunction: public base_local_planner::TrajectoryCostFunction {
public:
  OscillationCostFunction();
  virtual ~OscillationCostFunction();

  double scoreTrajectory(Trajectory &traj);

  bool prepare() {return true;};

  /**
   * @brief  Reset the oscillation flags for the local planner
   */
  void resetOscillationFlags();


  void updateOscillationFlags(Eigen::Vector3f pos, base_local_planner::Trajectory* traj, double min_vel_trans);

  void setOscillationResetDist(double dist, double angle);

private:

  void resetOscillationFlagsIfPossible(const Eigen::Vector3f& pos, const Eigen::Vector3f& prev);

  /**
   * @brief  Given a trajectory that's selected, set flags if needed to
   * prevent the robot from oscillating
   * @param  t The selected trajectory
   * @return True if a flag was set, false otherwise
   */
  bool setOscillationFlags(base_local_planner::Trajectory* t, double min_vel_trans);

  // flags
  bool strafe_pos_only_, strafe_neg_only_, strafing_pos_, strafing_neg_;
  bool rot_pos_only_, rot_neg_only_, rotating_pos_, rotating_neg_;
  bool forward_pos_only_, forward_neg_only_, forward_pos_, forward_neg_;

  // param
  double oscillation_reset_dist_, oscillation_reset_angle_;

  Eigen::Vector3f prev_stationary_pos_;
};

} /* namespace base_local_planner */
#endif /* OSCILLATION_COST_FUNCTION_H_ */
