#ifndef ODOMETRYREADING_H_
#define ODOMETRYREADING_H_

#include <string.h>
#include "sensorreading.h"
#include "gmapping/utils/point.h"
#include "odometrysensor.h"

namespace UstarSlam
{

	class OdometryReading : public SensorReading
	{
	public:
		OdometryReading(const OdometrySensor *odo, double time = 0);
		inline const OrientedPoint &getPose() const { return m_pose; }
		inline const OrientedPoint &getSpeed() const { return m_speed; }
		inline const OrientedPoint &getAcceleration() const { return m_acceleration; }
		inline void setPose(const OrientedPoint &pose) { m_pose = pose; }
		inline void setSpeed(const OrientedPoint &speed) { m_speed = speed; }
		inline void setAcceleration(const OrientedPoint &acceleration) { m_acceleration = acceleration; }

	protected:
		OrientedPoint m_pose;
		OrientedPoint m_speed;
		OrientedPoint m_acceleration;
	};

}; // namespace UstarSlam
#endif
