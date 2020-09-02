#ifndef SENSOR_H_
#define SENSOR_H_

#include <string>
#include <map>

namespace UstarSlam
{

	class Sensor
	{
	public:
		Sensor(const std::string &name = "");
		virtual ~Sensor();
		inline std::string getName() const { return m_name; }
		inline void setName(const std::string &name) { m_name = name; }

	protected:
		std::string m_name;
	};

	typedef std::map<std::string, Sensor *> SensorMap;

}; // namespace UstarSlam

#endif
