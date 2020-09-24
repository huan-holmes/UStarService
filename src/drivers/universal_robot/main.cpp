#include "universal_robot/universal_driver.h"
int main(int argc, char **argv)
{

    ros::init(argc, argv, "universal_driver");
    UniversalNode drive;
    drive.Run();
    return 0;
}
