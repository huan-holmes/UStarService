#ifndef _SENSORLOG_H_
#define _SENSORLOG_H_

#include <list>
#include <istream>
#include "gmapping/sensor/sensorreading.h"
#include "gmapping/sensor/odometrysensor.h"
#include "gmapping/sensor/rangesensor.h"
#include "gmapping/sensor/odometryreading.h"
#include "gmapping/sensor/rangereading.h"
#include "configuration.h"

namespace UstarSlam
{

	class SensorLog : public std::list<SensorReading *>
	{
		public:
			SensorLog(const SensorMap &);
			~SensorLog();
			std::istream &load(std::istream &is);
			OrientedPoint boundingBox(double &xmin, double &ymin, double &xmax, double &ymax) const;

		protected:
			const SensorMap &m_sensorMap;
			OdometryReading *parseOdometry(std::istream &is, const OdometrySensor *) const;
			RangeReading *parseRange(std::istream &is, const RangeSensor *) const;
	};

}; // namespace UstarSlam

#endif
