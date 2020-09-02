
#ifndef TRAJECTORYCOSTFUNCTION_H_
#define TRAJECTORYCOSTFUNCTION_H_

#include "planning/local_planner/trajectory.h"

namespace base_local_planner {

/**
 * @class TrajectoryCostFunction
 * @brief Provides an interface for critics of trajectories
 * During each sampling run, a batch of many trajectories will be scored using such a cost function.
 * The prepare method is called before each batch run, and then for each
 * trajectory of the sampling set, score_trajectory may be called.
 */
class TrajectoryCostFunction {
public:

  /**
   *
   * General updating of context values if required.
   * Subclasses may overwrite. Return false in case there is any error.
   */
  virtual bool prepare() = 0;

  /**
   * return a score for trajectory traj
   */
  virtual double scoreTrajectory(Trajectory &traj) = 0;

  double getScale() {
    return scale_;
  }

  void setScale(double scale) {
    scale_ = scale;
  }

  virtual ~TrajectoryCostFunction() {}

protected:
  TrajectoryCostFunction(double scale = 1.0): scale_(scale) {}

private:
  double scale_;
};

}

#endif /* TRAJECTORYCOSTFUNCTION_H_ */
