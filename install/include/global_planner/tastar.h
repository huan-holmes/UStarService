#ifndef TASTAR_H_
#define TASTAR_H_

#include "global_planner/planner_core.h"
#include "global_planner/expander.h"
#include <vector>
#include <algorithm>

namespace global_planner 
{
enum Direction {INCREASE, DECREASE};
class Index1 
{
    public:
        Index1(int a, float b) 
        {
            i = a;
            cost = b;
        }
        int i;
        float cost;
};

struct greater2 
{
        bool operator()(const Index1& a, const Index1& b) const 
        {
            return a.cost > b.cost;
        }
};

class TAStarExpansion : public Expander 
{
    public:
        TAStarExpansion(PotentialCalculator* p_calc, int nx, int ny);
        bool calculatePotentials(unsigned char* costs, double start_x, double start_y, double end_x, double end_y, int cycles,
                                float* potential);
    private:
        void add(unsigned char* costs, float* potential, int i, int next_i, int end_x, int end_y);
        std::vector<Index1> queue_;
        Direction direction_;
};

} //end namespace global_planner
#endif

