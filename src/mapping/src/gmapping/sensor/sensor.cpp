#include "gmapping/sensor/sensor.h"

namespace UstarSlam{

Sensor::Sensor(const std::string& name){
	m_name=name;
}

Sensor::~Sensor(){
}

};// end namespace
