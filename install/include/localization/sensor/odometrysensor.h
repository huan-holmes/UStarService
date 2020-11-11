#ifndef _ODOMETRYSENSOR_H_
#define _ODOMETRYSENSOR_H_

#include "localization/sensor/sensor.h"
#include "localization/pf/pf_pdf.h"

namespace UstarLocalization
{

typedef enum
{
  ODOM_MODEL_DIFF,
  ODOM_MODEL_OMNI,
  ODOM_MODEL_DIFF_CORRECTED,
  ODOM_MODEL_OMNI_CORRECTED
} odom_model_t;

// Odometric sensor data
class OdometrySensorData : public SensorData
{
  // Odometric pose
  public: 
    pf_vector_t pose;

  // Change in odometric pose
  public: 
    pf_vector_t delta;
};


// Odometric sensor model
class OdometrySensor : public Sensor
{
  // Default constructor
  public: OdometrySensor();

  public: void SetModelDiff(double alpha1, 
                            double alpha2, 
                            double alpha3, 
                            double alpha4);

  public: void SetModelOmni(double alpha1, 
                            double alpha2, 
                            double alpha3, 
                            double alpha4,
                            double alpha5);

  public: void SetModel( odom_model_t type,
                         double alpha1,
                         double alpha2,
                         double alpha3,
                         double alpha4,
                         double alpha5 = 0 );

  // Update the filter based on the action model.  Returns true if the filter
  // has been updated.
  public: virtual bool UpdateAction(pf_t *pf, SensorData *data);

  // Current data timestamp
  private: double time;
  
  // Model type
  private: odom_model_t model_type;

  // Drift parameters
  private: double alpha1, alpha2, alpha3, alpha4, alpha5;
};


}

#endif
