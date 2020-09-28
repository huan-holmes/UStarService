#ifndef LOCAL_PLANNER_STATE_H_
#define LOCAL_PLANNER_STATE_H_

namespace base_local_planner
{
    enum LocalPlannerState{
        ACCELERATE,
        DECELERATE,
        VIRTUALROUTE
    };
};

#endif