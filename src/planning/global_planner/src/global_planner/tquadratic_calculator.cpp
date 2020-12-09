
#include "global_planner/tquadratic_calculator.h"

namespace global_planner {
float TQuadraticCalculator::calculatePotential(float* potential, unsigned char cost, int n, float prev_potential) {
    // get neighbors
    float u, d, l, r, lu, ld, ru, rd;
    l = potential[n - 1];
    r = potential[n + 1];
    u = potential[n - nx_ * 1];
    d = potential[n + nx_ * 1];
    lu = potential[n + nx_ * 1 -1];
    ld = potential[n - nx_ * 1 - 1];
    ru = potential[n + nx_ * 1 + 1];
    ru = potential[n - nx_ * 1 + 1];

    float um, cm, dm, mm;
    um = u < lu ? (u < ru ? u : ru) : (lu < ru ? lu : ru);
    cm = l < r ? l : r;
    dm = d < ld ? (d < rd ? d : rd) : (ld < rd ? ld : rd);
    mm = cm < um ? (cm < dm ? cm : dm) : (um < dm ? um : dm);
    //  ROS_INFO("[Update] c: %f  l: %f  r: %f  u: %f  d: %f\n",
    //     potential[n], l, r, u, d);
    //  ROS_INFO("[Update] cost: %d\n", costs[n]);

    // find lowest, and its lowest neighbor
    // float ta, tc;
    // if (l < r)
    //     tc = l;
    // else
    //     tc = r;
    // if (u < d)
    //     ta = u;
    // else
    //     ta = d;

    float hf = cost; // traversability factor
    // float dc = tc - ta;        // relative cost between ta,tc
    // if (dc < 0)         // tc is lowest
    // {
    //     dc = -dc;
    //     ta = tc;
    // }
    float ta, dc;
    ta = mm;
    dc = (um - mm) < (cm - mm) ? ((um - mm) < (dm - mm) ? (um -mm) : (dm -mm)) : ((cm - mm) < (dm - mm) ? (cm - mm) : (dm - mm));

    // calculate new potential
    if (dc >= hf)        // if too large, use ta-only update
        return ta + hf;
    else            // two-neighbor interpolation update
    {
        // use quadratic approximation
        // might speed this up through table lookup, but still have to
        //   do the divide
        float d = dc / hf;
        float v = -0.2301 * d * d + 0.5307 * d + 0.7040;
        return ta + hf * v;
    }
}
}

