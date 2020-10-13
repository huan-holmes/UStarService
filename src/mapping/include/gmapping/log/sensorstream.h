#ifndef _SENSORSTREAM_H_
#define _SENSORSTREAM_H_

#include <istream>
#include "sensorlog.h"

namespace UstarSlam
{
	class SensorStream
	{
		public:
			SensorStream(const SensorMap &sensorMap);
			virtual ~SensorStream();
			virtual operator bool() const = 0;
			virtual bool rewind() = 0;
			virtual SensorStream &operator>>(const SensorReading *&) = 0;
			inline const SensorMap &getSensorMap() const { return m_sensorMap; }

		protected:
			const SensorMap &m_sensorMap;
			static SensorReading *parseReading(std::istream &is, const SensorMap &smap);
			static OdometryReading *parseOdometry(std::istream &is, const OdometrySensor *);
			static RangeReading *parseRange(std::istream &is, const RangeSensor *);
	};

	class InputSensorStream : public SensorStream
	{
		public:
			InputSensorStream(const SensorMap &sensorMap, std::istream &is);
			virtual operator bool() const;
			virtual bool rewind();
			virtual SensorStream &operator>>(const SensorReading *&);

			//virtual SensorStream& operator >>(SensorLog*& log);
		protected:
			std::istream &m_inputStream;
	};

	class LogSensorStream : public SensorStream
	{
		public:
			LogSensorStream(const SensorMap &sensorMap, const SensorLog *log);
			virtual operator bool() const;
			virtual bool rewind();
			virtual SensorStream &operator>>(const SensorReading *&);

		protected:
			const SensorLog *m_log;
			SensorLog::const_iterator m_cursor;
	};

}; // namespace UstarSlam
#endif
