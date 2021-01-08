#ifndef TQUADRATIC_CALCULATOR_H_
#define TQUADRATIC_CALCULATOR_H_
#include <vector>
#include "global_planner/potential_calculator.h"

namespace global_planner 
{

class TQuadraticCalculator : public PotentialCalculator 
{
    public:
        TQuadraticCalculator(int nx, int ny): PotentialCalculator(nx,ny) {}

        float calculatePotential(float* potential, unsigned char cost, int n, float prev_potential);
};


} //end namespace global_planner
#endif
