#ifndef _CARMENCONFIGURATION_H_
#define _CARMENCONFIGURATION_H_

#include <string>
#include <map>
#include <vector>
#include <istream>
#include "gmapping/sensor/sensor.h"
#include "gmapping/log/configuration.h"

namespace UstarSlam
{

	class CarmenConfiguration : public Configuration, public std::map<std::string, std::vector<std::string>>
	{
		public:
			virtual std::istream &load(std::istream &is);
			virtual SensorMap computeSensorMap() const;
	};

}; // namespace UstarSlam

#endif
