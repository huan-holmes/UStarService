#ifndef _SENSORREADING_H_
#define _SENSORREADING_H_

#include "sensor.h"

namespace UstarSlam
{
    class SensorReading
    {
        public:
            SensorReading(const Sensor *s = 0, double time = 0);
            virtual ~SensorReading();
            inline double getTime() const { return m_time; }
            inline void setTime(double t) { m_time = t; }
            inline const Sensor *getSensor() const { return m_sensor; }

        protected:
            double m_time;
            const Sensor *m_sensor;
    };
}; // namespace UstarSlam
#endif 
