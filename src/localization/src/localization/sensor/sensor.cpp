#include "localization/sensor/sensor.h"

namespace UstarLocalization
{

  ////////////////////////////////////////////////////////////////////////////////
  // Default constructor
  Sensor::Sensor()
  {
    return;
  }

  Sensor::~Sensor()
  {
  }

  ////////////////////////////////////////////////////////////////////////////////
  // Apply the action model
  bool Sensor::UpdateAction(pf_t *pf, SensorData *data)
  {
    return false;
  }

  ////////////////////////////////////////////////////////////////////////////////
  // Initialize the filter
  bool Sensor::InitSensor(pf_t *pf, SensorData *data)
  {
    return false;
  }

  ////////////////////////////////////////////////////////////////////////////////
  // Apply the sensor model
  bool Sensor::UpdateSensor(pf_t *pf, SensorData *data)
  {
    return false;
  }

#ifdef INCLUDE_RTKGUI

  ////////////////////////////////////////////////////////////////////////////////
  // Setup the GUI
  void AMCLSensor::SetupGUI(rtk_canvas_t *canvas, rtk_fig_t *robot_fig)
  {
    return;
  }

  ////////////////////////////////////////////////////////////////////////////////
  // Shutdown the GUI
  void AMCLSensor::ShutdownGUI(rtk_canvas_t *canvas, rtk_fig_t *robot_fig)
  {
    return;
  }

  ////////////////////////////////////////////////////////////////////////////////
  // Draw sensor data
  void AMCLSensor::UpdateGUI(rtk_canvas_t *canvas, rtk_fig_t *robot_fig, AMCLSensorData *data)
  {
    return;
  }

#endif
}; // namespace UstarLocalization