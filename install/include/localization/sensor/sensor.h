#ifndef _SENSOR_H_
#define _SENSOR_H_

#include "localization/pf/pf.h"

namespace UstarLocalization
{

  // Forward declarations
  class SensorData;

  // Base class for all AMCL sensors
  class Sensor
  {
    // Default constructor
    public:
      Sensor();

    // Default destructor
    public:
      virtual ~Sensor();

    // Update the filter based on the action model.  Returns true if the filter
    // has been updated.
    public:
      virtual bool UpdateAction(pf_t *pf, SensorData *data);

    // Initialize the filter based on the sensor model.  Returns true if the
    // filter has been initialized.
    public:
      virtual bool InitSensor(pf_t *pf, SensorData *data);

    // Update the filter based on the sensor model.  Returns true if the
    // filter has been updated.
    public:
      virtual bool UpdateSensor(pf_t *pf, SensorData *data);

    // Flag is true if this is the action sensor
    public:
      bool is_action;

    // Action pose (action sensors only)
    public:
      pf_vector_t pose;

   // AMCL Base
    //protected: AdaptiveMCL & AMCL;

#ifdef INCLUDE_RTKGUI
    // Setup the GUI
  public:
    virtual void SetupGUI(rtk_canvas_t *canvas, rtk_fig_t *robot_fig);

    // Finalize the GUI
  public:
    virtual void ShutdownGUI(rtk_canvas_t *canvas, rtk_fig_t *robot_fig);

    // Draw sensor data
  public:
    virtual void UpdateGUI(rtk_canvas_t *canvas, rtk_fig_t *robot_fig, AMCLSensorData *data);
#endif
  };

  // Base class for all AMCL sensor measurements
  class SensorData
  {
    // Pointer to sensor that generated the data
    public:
      Sensor *sensor;
      virtual ~SensorData() {}

    // Data timestamp
    public:
      double time;
  };

}; // namespace UstarLocalization

#endif
