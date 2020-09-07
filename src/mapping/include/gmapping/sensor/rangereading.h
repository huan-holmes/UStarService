#ifndef RANGEREADING_H_
#define RANGEREADING_H_

#include <vector>
#include "sensorreading.h"
#include "rangesensor.h"

namespace UstarSlam
{

    class RangeReading : public SensorReading, public std::vector<double>
    {
    public:
        RangeReading(const RangeSensor *rs, double time = 0);
        RangeReading(unsigned int n_beams, const double *d, const RangeSensor *rs, double time = 0);
        virtual ~RangeReading();
        inline const OrientedPoint &getPose() const { return m_pose; }
        inline void setPose(const OrientedPoint &pose) { m_pose = pose; }
        unsigned int rawView(double *v, double density = 0.) const;
        std::vector<Point> cartesianForm(double maxRange = 1e6) const;
        unsigned int activeBeams(double density = 0.) const;

    protected:
        OrientedPoint m_pose;
    };

}; // namespace UstarSlam

#endif
