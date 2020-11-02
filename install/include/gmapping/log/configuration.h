#ifndef _CONFIGURATION_H_
#define _CONFIGURATION_H_

#include <istream>
#include "gmapping/sensor/sensor.h"

namespace UstarSlam
{

	class Configuration
	{
		public:
			virtual ~Configuration();
			virtual SensorMap computeSensorMap() const = 0;
	};

}; // namespace UstarSlam
#endif
