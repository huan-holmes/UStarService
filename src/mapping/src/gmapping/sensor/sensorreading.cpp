#include "gmapping/sensor/sensorreading.h"

namespace UstarSlam
{
	SensorReading::SensorReading(const Sensor* s, double t)
	{
		m_sensor=s;
		m_time=t;
	}

	SensorReading::~SensorReading()
	{
	}
};

