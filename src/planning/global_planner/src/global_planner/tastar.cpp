
#include "global_planner/tastar.h"
#include "costmap/utils/cost_values.h"

namespace global_planner {

TAStarExpansion::TAStarExpansion(PotentialCalculator* p_calc, int xs, int ys) :
        Expander(p_calc, xs, ys), direction_(INCREASE)
{

}

bool TAStarExpansion::calculatePotentials(unsigned char* costs, double start_x, double start_y, double end_x, double end_y,
                                        int cycles, float* potential) {
    
    if (start_y > end_y)
        direction_ = DECREASE;
    if (start_y <= end_y)
        direction_ = INCREASE;
    queue_.clear();
    int start_i = toIndex(start_x, start_y);
    queue_.push_back(Index1(start_i, 0));

    std::fill(potential, potential + ns_, POT_HIGH);
    potential[start_i] = 0;

    int goal_i = toIndex(end_x, end_y);
    int cycle = 0;

    while (queue_.size() > 0 && cycle < cycles) {
        Index1 top = queue_[0];
        std::pop_heap(queue_.begin(), queue_.end(), greater2());
        queue_.pop_back();

        int i = top.i;
        if (i == goal_i)
            return true; 

        add(costs, potential, i, i + 1, end_x, end_y);
        add(costs, potential, i, i - 1, end_x, end_y);
        add(costs, potential, i, i + nx_, end_x, end_y);
        add(costs, potential, i, i - nx_, end_x, end_y);
        //add(costs, potential, i, i + nx_ + 1, end_x, end_y);
        //add(costs, potential, i, i - nx_ + 1, end_x, end_y);
        //add(costs, potential, i, i + nx_ - 1, end_x, end_y);
        //add(costs, potential, i, i - nx_ - 1, end_x, end_y);

        cycle++;
    }

    return false;
}

void TAStarExpansion::add(unsigned char* costs, float* potential, int i, int next_i, int end_x,
                         int end_y) {
    if (next_i < 0 || next_i >= ns_)
        return;

    if (potential[next_i] < POT_HIGH)
        return;

    if(costs[next_i]>=lethal_cost_ && !(unknown_ && costs[next_i]==UstarCostmap::NO_INFORMATION))
        return;
    neutral_cost_ = 50;
    
    float prev_potential = potential[i];
    int x_prev = i % nx_, y_prev = i / nx_;
    int x = next_i % nx_, y = next_i / nx_;

    if (direction_ == INCREASE && x >= x_prev && y_prev <= end_y)
        neutral_cost_ = 1;
    if (direction_ == DECREASE && x <= x_prev && y_prev >= end_y)
        neutral_cost_ = 1;
    
    //ROS_INFO("direction: %d, prev_x: %d, prev_y: %d, x: %d, y: %d, end_y: %d, cost: %d", direction_, x_prev, y_prev, x, y, end_y, int(neutral_cost_));
    potential[next_i] = p_calc_->calculatePotential(potential, costs[next_i] + neutral_cost_, next_i, prev_potential);
    
    // if (abs(next_i - i) <= nx_)
    // {
    //      potential[next_i] = p_calc_->calculatePotential(potential, costs[next_i] + neutral_cost_, next_i, prev_potential);

    // }
    // else
    // {
    //     potential[next_i] = p_calc_->calculatePotential(potential, costs[next_i] + neutral_cost_ * sqrt(2), next_i, prev_potential);
    // }
    
    float distance = abs(end_x - x) + abs(end_y - y);

    queue_.push_back(Index1(next_i, potential[next_i] + distance * neutral_cost_));
    std::push_heap(queue_.begin(), queue_.end(), greater2());
}

} //end namespace global_planner
