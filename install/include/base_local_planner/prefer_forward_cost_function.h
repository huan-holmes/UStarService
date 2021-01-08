#ifndef PREFER_FORWARD_COST_FUNCTION_H_
#define PREFER_FORWARD_COST_FUNCTION_H_

#include <base_local_planner/trajectory_cost_function.h>

namespace base_local_planner {

class PreferForwardCostFunction: public base_local_planner::TrajectoryCostFunction {
public:

  PreferForwardCostFunction(double penalty) : penalty_(penalty) {}
  ~PreferForwardCostFunction() {}

  double scoreTrajectory(Trajectory &traj);

  bool prepare() {return true;};

  void setPenalty(double penalty) {
    penalty_ = penalty;
  }

private:
  double penalty_;
};

} /* namespace base_local_planner */
#endif /* PREFER_FORWARD_COST_FUNCTION_H_ */
