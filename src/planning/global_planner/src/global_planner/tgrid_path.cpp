
#include "global_planner/tgrid_path.h"
#include <algorithm>
#include <stdio.h>
#include <ros/ros.h>

namespace global_planner {

bool TGridPath::getPath(float* potential, double start_x, double start_y, double end_x, double end_y, std::vector<std::pair<float, float> >& path) {
    std::pair<float, float> current;
    current.first = end_x;
    current.second = end_y;

    int start_index = getIndex(start_x, start_y);

    path.push_back(current);
    int c = 0;
    int ns = xs_ * ys_;
    
    while (getIndex(current.first, current.second) != start_index) {
        float min_val = 1e10;
        int min_x = 0, min_y = 0;
        //cost_.clear();
        //point2_.clear();
        for (int xd = -1; xd <= 1; xd++) {
            for (int yd = -1; yd <= 1; yd++) {
                if (xd == 0 && yd == 0)
                    continue;
                if (abs(xd) + abs(yd) > 1)
                    continue;
                int x = current.first + xd, y = current.second + yd;
                int index = getIndex(x, y);
                // Point2 p(x, y);
               
                // point2_.push_back(p);
                // cost_.push_back(potential[index]);
                if (potential[index] < min_val) 
                {
                    min_val = potential[index];
                    min_x = x;
                    min_y = y;
                }
            }
        }
        // for (int i = 0; i < cost_.size(); i++)
        // { 
        //     char d = cost_[i];
        //     int count_min = 0;
        //     int count_max = 0;
            
        //     for (int j = 0; j < cost_.size(); j++)
        //     {
        //         if (d < cost_[j])
        //         {
        //             count_min++;
        //         }
        //         else
        //         {
        //             count_max++;
        //         }
        //     }
        //     if (abs(count_min - count_max) <=1)
        //     {
                
        //         min_x = point2_[i].a;
        //         min_y = point2_[i].b;
        //         //ROS_INFO("i: %d, x: %d, y: %d", i, min_x, min_y);
        //         break;
        //     }
            
        // }
        if (min_x == 0 && min_y == 0)
            return false;
        current.first = min_x;
        current.second = min_y;
        path.push_back(current);
        
        if(c++>ns*4){
            return false;
        }

    }
    return true;
}

} //end namespace global_planner

