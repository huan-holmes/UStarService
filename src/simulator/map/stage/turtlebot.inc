define kinect ranger
(
  sensor
  (
    range_max 20
    fov 270.0
    samples 1536
  )
  # generic model properties
  color "black"
  size [ 0.06 0.15 0.03 ]
)

define turtlebot position
(
  pose [ 0.0 0.0 0.0 0.0 ]
  localization "odom"
  #odom_error [0.03 0.03 999999 999999 999999 0.02]
  odom_error [0.000003 0.000003 0.0 0.000002]
  size [ 0.2552 0.2552 0.40 ]
  origin [ 0.0 0.0 0.0 0.0 ]
  gui_nose 1
  drive "diff"
  color "gray"
  
  kinect(pose [ -0.1 0.0 -0.11 0.0 ])
)