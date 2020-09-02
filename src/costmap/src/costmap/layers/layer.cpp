#include "costmap/layers/layer.h"

namespace UstarCostmap
{

  Layer::Layer()
      : layered_costmap_(NULL), current_(false), enabled_(false), name_(), tf_(NULL)
  {
  }

  void Layer::initialize(LayeredCostmap *parent, std::string name, tf2_ros::Buffer *tf)
  {
    layered_costmap_ = parent;
    name_ = name;
    tf_ = tf;
    onInitialize();
  }

  const std::vector<geometry_msgs::Point> &Layer::getFootprint() const
  {
    return layered_costmap_->getFootprint();
  }

} // namespace UstarCostmap
