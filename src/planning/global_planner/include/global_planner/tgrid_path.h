#ifndef TGRID_PATH_H_
#define TGRID_PATH_H_
#include <vector>
#include "global_planner/traceback.h"

namespace global_planner 
{

class Point2
{
public:
    Point2(int x, int y): a(x), b(y) {}
    int a;
    int b;
};
class TGridPath : public Traceback 
{
    public:
        TGridPath(PotentialCalculator* p_calc): Traceback(p_calc){}
        bool getPath(float* potential, double start_x, double start_y, double end_x, double end_y, std::vector<std::pair<float, float> >& path);
        std::vector<Point2> point2_;
        std::vector<char> cost_;
};

} //end namespace global_planner
#endif