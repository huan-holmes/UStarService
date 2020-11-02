#include "universal_robot/universal_driver.h"



bool UniversalDrive::DataGet() {
    int buf_size = 1000;
    uint8_t buf[buf_size] = {};
    int ReadNum = read(fd_, buf, buf_size);
    if (ReadNum == -1) {
        std::cout << "serial port get message fail" << ReadNum << std::endl;
        return false;
    } else {
        if (ReadNum > 0) {
            int i = 0;
            while (i < ReadNum) {
                Decode(buf[i]);
                ++i;
            }
        }
        return true;
    }
}

void UniversalDrive::Test() {
    //odule_type_.diff_ = 1;
    geometry_msgs::Twist  test_vel;
    //test_vel.angular.z = -0.1;
    test_vel.linear.x = -0.002;
    SentRpm(test_vel);
}

void UniversalDrive::Decode(const uint8_t dat) {
    static int is_start = 0;
    if ((dat == 0xAA) && is_start == 0) {
        is_start = 1;
    }
    if ((dat == 0x55) && is_start == 1) {
        is_start = 2;
        return;
    }
    if (is_start == 2) {
        if (packet_.size() == 0) {
            packet_.push_back(dat);
            return;
        }
        if (packet_.size() == packet_[0]) {
            is_start = 0;
            CheckData();
            packet_.clear();
        } else {
            packet_.push_back(dat);
        }
    }
}

void UniversalDrive::CheckData() {
    if (packet_.size() < 1) {
        return;
    }
    uint16_t crc16 = CRC16(&packet_[0], packet_.size() - 2);
    int16char2 crc;
    memcpy(&crc.c_sr, &packet_[packet_.size() -  sizeof(int16char2)], sizeof(int16char2));
    if (crc16 != crc.u_data) {
        std::cout << "odom crc error " << std::endl;
        return;
    }
    if (FourWheelFlag == packet_[1]) {
        static FourWheel four_wheel;
        memcpy(&four_wheel, &packet_[2], sizeof(FourWheel));
        static double last_time  = four_wheel.stamp;
        info_.stamp = four_wheel.stamp;
        module_type_.four_wheel = 1;
        if (four_wheel.type) {
            info_.vel = (four_wheel.left_front + four_wheel.right_front)
                        * kinematic_.wheel_radius * 2 * M_PI / (2 * kinematic_.slow_down * 60);
            info_.distance = fabs(four_wheel.stamp - last_time) * info_.vel / 1000;
        } else {
        }
        last_time = four_wheel.stamp;
        //std::cout << four_wheel.stamp<< " "<< four_wheel.type<< " "<< four_wheel.left_back
         //         << " "<< four_wheel.left_front<< " "<< four_wheel.right_back<< " "<< four_wheel.right_front<<std::endl;
        return;
    }
    if (AckerManNormallFlag == packet_[1]) {
        static AckerManNormal ackerman_normal;
        memcpy(&ackerman_normal, &packet_[2], sizeof(AckerManNormal));
        static double last_time  = ackerman_normal.stamp;
        info_.stamp = ackerman_normal.stamp;
        module_type_.ackerMan_normal = 1;
        if (ackerman_normal.type) {
            info_.vel = (ackerman_normal.back)
                        * kinematic_.wheel_radius * 2 * M_PI / (1 * kinematic_.slow_down * 60);
            info_.distance = fabs(ackerman_normal.stamp - last_time) * info_.vel / 1000;
        } else {
        }
        last_time = ackerman_normal.stamp;
        return;
    }
    if (DiffFlag == packet_[1]) {
        static Diff diff;
        memcpy(&diff, &packet_[2], sizeof(Diff));
        static double last_time  = diff.stamp;
        info_.stamp = diff.stamp;
        module_type_.diff_ = 1;
        if (diff.type) {
            info_.vel = (diff.left + diff.right)
                        * kinematic_.wheel_radius * 2 * M_PI / (2 * kinematic_.slow_down * 60);
            info_.w = ( diff.right - diff.left )
                        * kinematic_.wheel_radius * 2 * M_PI / (kinematic_.wheel_gauge* kinematic_.slow_down * 60);

            info_.distance = fabs(diff.stamp - last_time) * info_.vel / 1000;
            info_.d_w = fabs(diff.stamp - last_time) * info_.w / 1000;

        } else {
        }
        last_time = diff.stamp;
        return;
    }



    if ((module_type_.four_wheel + module_type_.ackerMan_normal + module_type_.diff_) > 1) {
        std::cout << " kinematic model error please confirm unique " << std::endl;
        return;
    }
}

void UniversalDrive::SentRpm(const geometry_msgs::Twist cmd_vel) {

    if (module_type_.diff_) {
        Diff diff;
        uint8_t size = sizeof(Diff) + 8;
        uint8_t buffer[size] ;
        buffer[0] = Head1;
        buffer[1] = Head2;
        buffer[2] = size - 4;
        buffer[3] = DiffFlag;
        buffer[size - 2] = End1;
        buffer[size - 1] = End2;
        diff.type = 1;
        diff.stamp = ros::Time::now().toSec() * 1000;
        diff.right = (2 * cmd_vel.linear.x + cmd_vel.angular.z * kinematic_.wheel_gauge) * kinematic_.slow_down * 60 /
                     (2 * kinematic_.wheel_radius * 2 * M_PI); //rpm
        diff.left = (2 * cmd_vel.linear.x - cmd_vel.angular.z * kinematic_.wheel_gauge) * kinematic_.slow_down * 60 /
                    (2 * kinematic_.wheel_radius * 2 * M_PI); //RPM
        memcpy(&buffer[4], &diff, sizeof(Diff));
        SenCmdVel(buffer,size);
        return;
    }
    if (module_type_.four_wheel) {
        FourWheel four_whell;
        uint8_t size = sizeof(FourWheel) + 8;
        uint8_t  buffer[size] ;
        buffer[0] = Head1;
        buffer[1] = Head2;
        buffer[2] = size - 4;
        buffer[3] = FourWheelFlag;
        buffer[size - 2] = End1;
        buffer[size - 1] = End2;
        four_whell.type = 1;
        four_whell.stamp = ros::Time::now().toSec() * 1000;
        four_whell.right_front = (2 * cmd_vel.linear.x + cmd_vel.angular.z * kinematic_.wheel_gauge) * kinematic_.slow_down * 60 /
                                 (2 * kinematic_.wheel_radius * 2 * M_PI); //rpm
        four_whell.left_front = (2 * cmd_vel.linear.x - cmd_vel.angular.z * kinematic_.wheel_gauge) * kinematic_.slow_down * 60 /
                                (2 * kinematic_.wheel_radius * 2 * M_PI); //RPM
        four_whell.right_back = four_whell.right_front;
        four_whell.left_back = four_whell.left_front;
        memcpy(&buffer[4], &four_whell, sizeof(FourWheel));
        SenCmdVel(buffer,size);
        return;
    }
    if (module_type_.ackerMan_normal) {
        AckerManNormal acker_whell;
        uint8_t size = sizeof(AckerManNormal) + 8;
        uint8_t  buffer[size] ;
        buffer[0] = Head1;
        buffer[1] = Head2;
        buffer[2] = size - 4;
        buffer[3] = AckerManNormallFlag;
        buffer[size - 2] = End1;
        buffer[size - 1] = End2;
        acker_whell.type = 1;
        acker_whell.stamp = ros::Time::now().toSec() * 1000;
        acker_whell.back   =  cmd_vel.linear.x  * kinematic_.slow_down * 60 /( kinematic_.wheel_radius * 2 * M_PI); //rpm

        acker_whell.right_front = acker_whell.left_front = cmd_vel.linear.y*1000;
        memcpy(&buffer[4], &acker_whell, sizeof(AckerManNormal));
        SenCmdVel(buffer,size);
        return;
    }
}


void UniversalDrive::SenCmdVel( uint8_t* buffer,const uint8_t size){
    int16char2 crc;
    crc.u_data  = CRC16(buffer +2, size - 6);
    memcpy( buffer+ (size - 4), crc.c_sr, sizeof(int16char2));
//    int i = 0;
//    while (i < 32) {
//        Decode(buffer[i]);
//        ++i;
//    }
    int write_size =  write(fd_, buffer, size);

}

unsigned short UniversalDrive::CRC16(unsigned char* puchMsg, unsigned short usDataLen) {
    unsigned char uchCRCHi = 0xFF; /* �?CRC 字节初始�?*/
    unsigned char uchCRCLo = 0xFF; /* �?CRC 字节初始�?*/
    unsigned short uIndex;         /* CRC 循环中的索引 */
    while (usDataLen--) {          /* 传输消息缓冲�?*/
        uIndex = uchCRCLo ^ *puchMsg++; /* 计算 CRC */
        uchCRCLo = uchCRCHi ^ auchCRCHi[uIndex];
        uchCRCHi = auchCRCLo[uIndex];
    }
    return (uchCRCHi << 8 | uchCRCLo);
}

int UniversalDrive::OpenSerial(const char* serial_dev_name) {
    //O_RDWR 读写方式打开；O_NOCTTY 不允许进程管理串口（不太理解，一般都选上）；O_NDELAY 非阻塞（默认为阻塞，打开后也可以使用fcntl()重新设置）
    int fd_serial = open(serial_dev_name, O_RDWR | O_NOCTTY);
    if (-1 == fd_serial) {
        printf("Open serial port error ");
        return -1;
    }
    fd_ = fd_serial;
    return fd_serial;
}

int UniversalDrive::SerialSet(int fd, int speed, int flow_ctrl, int databits, int stopbits, int parity) {
    int speed_arr[] = {B115200, B19200, B9600, B4800, B2400, B1200, B300};
    int name_arr[] = {115200, 19200, 9600, 4800, 2400, 1200, 300};
    struct termios options;
    if (tcgetattr(fd, &options) !=  0) {
        perror("SetupSerial 1");
        return -1;
    }
    for (int i = 0; i < sizeof(speed_arr) / sizeof(int); i++) {
        if (speed == name_arr[i]) {
            cfsetispeed(&options, speed_arr[i]);
            cfsetospeed(&options, speed_arr[i]);
        }
    }
    options.c_cflag |= CLOCAL;
    options.c_cflag |= CREAD;
    switch (flow_ctrl) {
    case 0 :
        options.c_cflag &= ~CRTSCTS;
        break;
    case 1 :
        options.c_cflag |= CRTSCTS;
        break;
    case 2 :
        options.c_cflag |= IXON | IXOFF | IXANY;
        break;
    }
    options.c_cflag &= ~CSIZE;
    switch (databits) {
    case 5 :
        options.c_cflag |= CS5;
        break;
    case 6 :
        options.c_cflag |= CS6;
        break;
    case 7    :
        options.c_cflag |= CS7;
        break;
    case 8 :
        options.c_cflag |= CS8;
        break;
    default:
        fprintf(stderr, "Unsupported data size\n");
        return -1;
    }
    switch (parity) {
    case 'n':
    case 'N':
        options.c_cflag &= ~PARENB;
        options.c_iflag &= ~INPCK;
        break;
    case 'o':
    case 'O':
        options.c_cflag |= (PARODD | PARENB);
        options.c_iflag |= INPCK;
        break;
    case 'e':
    case 'E':
        options.c_cflag |= PARENB;
        options.c_cflag &= ~PARODD;
        options.c_iflag |= INPCK;
        break;
    case 's':
    case 'S':
        options.c_cflag &= ~PARENB;
        options.c_cflag &= ~CSTOPB;
        break;
    default:
        fprintf(stderr, "Unsupported parity\n");
        return -1;
    }
    switch (stopbits) {
    case 1:
        options.c_cflag &= ~CSTOPB;
        break;
    case 2:
        options.c_cflag |= CSTOPB;
        break;
    default:
        fprintf(stderr, "Unsupported stop bits\n");
        return -1;
    }
    options.c_oflag &= ~(ONLCR | OCRNL);
    options.c_iflag &= ~(ICRNL | INLCR);
    options.c_iflag &= ~(IXON | IXOFF | IXANY);
    options.c_oflag &= ~OPOST;
    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    //options.c_lflag &= ~(ISIG | ICANON);
    options.c_cc[VTIME] = 1;
    options.c_cc[VMIN] = 0;//14;
    tcflush(fd, TCIFLUSH);
    if (tcsetattr(fd, TCSANOW, &options) != 0) {
        perror("com set error!\n");
        return 0;
    }
    return 1;
}

UniversalNode::UniversalNode() {
    odom_pub = nh.advertise<nav_msgs::Odometry>("odom", 1); //

    sub_cmd_vel = nh.subscribe("cmd_vel", 1, &UniversalNode::control_vel , this);
    sub_imu_msgs = nh.subscribe("imu", 1, &UniversalNode::get_imu_msgs , this);
    ros::NodeHandle n("~");
    bool read_from_rosparam ;
    n.param<bool>("read_from_rosparam", read_from_rosparam, false);
    if (read_from_rosparam) {
        while (nh.getParam("robooster_odom_dev", odom_dev_) == false && ros::ok()) {
            std::cout << "robooster_odom_dev is not set. please init param" << std::endl;
            sleep(1);
        }
    } else {
        odom_dev_ = "/dev/ttyS0";
    }
    nh.param<float>("robooster_slow_down", kinematic_.slow_down, 1.0);
    nh.param<float>("robooster_wheel_radius", kinematic_.wheel_radius, 0.083);
    nh.param<float>("robooster_encoder_lines", kinematic_.encoder_lines, 1024);
    nh.param<float>("robooster_wheel_gauge", kinematic_.wheel_gauge, 0.13313);
    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "read_from_rosparam " << read_from_rosparam << ",robooster_odom_dev " << odom_dev_ << std::endl;
    std::cout << "robooster_slow_down " << kinematic_.slow_down << "robooster_wheel_radius " << kinematic_.wheel_radius <<
              "robooster_encoder_lines " << kinematic_.encoder_lines <<  "robooster_wheel_gauge " << kinematic_.wheel_gauge <<
              std::endl;
    std::cout << "-----------------------------------------------------------------" << std::endl;
    drive_.kinematic_ = kinematic_;
}

void UniversalNode::Run() {
    int fd = drive_.OpenSerial(odom_dev_.c_str());
    if (fd == 0 || fd == -1) {
        std::cout << "open serial faild :" << odom_dev_ << std::endl;
        return ;
    }
    drive_.SerialSet(fd, 115200, 0, 8, 1, 'N');
    ros::Rate loop_rate(50.0);
    uint32_t last_mseconds = 0;
    int num = 0;
    while (ros::ok()) {
        //drive_.Test();
        drive_.DataGet();

        if(abs(drive_.info_.stamp - last_mseconds) > 40){
            std::cout << " odom data: time delayed!" << std::endl;
            last_mseconds = drive_.info_.stamp ;
            loop_rate.sleep();
            continue;
        }

        if (fabs(drive_.info_.stamp - last_mseconds) < 0.00001 ) {
            ++num;
            if(num>10){
                odom_is_update_ = false;
                std::cout << " odom data: time repeated!" << std::endl;
                last_mseconds = drive_.info_.stamp ;
                loop_rate.sleep();
                continue;
            }
        } else {
            odom_is_update_ = true;
            num = 0;
        }
        PublicOdom(drive_.info_.vel, drive_.info_.distance);
        last_mseconds = drive_.info_.stamp ;
        loop_rate.sleep();
        ros::spinOnce();
    }
}

void UniversalNode::PublicOdom(const double v, const double distance) {
    //数据填充发布
    //ROS_INFO_STREAM("----publicOdom()----");
    static double theta = 0;
    static double odom_x = 0;
    static double odom_y = 0;
    //theta = angles::normalize_angle(theta + GetDtheta()); //imu
    theta = angles::normalize_angle(theta + drive_.info_.d_w);// odom

    geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(theta);
    odom_x += distance  * cos(theta);
    odom_y += distance * sin(theta);
    odom_msg.header.frame_id = "odom"; //里程计数据填充
    odom_msg.child_frame_id = "base_link";
    odom_msg.header.stamp = ros::Time::now();
    odom_msg.pose.pose.position.x = odom_x;
    odom_msg.pose.pose.position.y = odom_y;
    odom_msg.pose.pose.position.z = 0;
    odom_msg.twist.twist.linear.x = v;
    odom_msg.twist.twist.linear.y = 0;
    odom_msg.twist.twist.linear.z = 0;
    odom_msg.twist.twist.angular = imu_msgs_.angular_velocity;
    odom_msg.pose.pose.orientation = odom_quat;
    odom_msg.pose.covariance[0] = 1e-3;
    odom_msg.pose.covariance[7] = 1e-3;
    odom_msg.pose.covariance[14] = 1e6;
    odom_msg.pose.covariance[21] = 1e6;
    odom_msg.pose.covariance[28] = 1e6;
    odom_msg.pose.covariance[35] = 1e3;
    geometry_msgs::TransformStamped odom_trans; //tf变换，里程计与baselink的
    odom_trans.header.frame_id = "odom";
    odom_trans.child_frame_id = "base_link";
    odom_trans.header.stamp = ros::Time::now();
    odom_trans.transform.translation.x = odom_x;
    odom_trans.transform.translation.y = odom_y;
    odom_trans.transform.translation.z = 0;
    odom_trans.transform.rotation = odom_quat;
    //
    odom_broadcaster.sendTransform(odom_trans);
    odom_pub.publish(odom_msg);
}



double UniversalNode::GetDtheta() {
    static ros::Time last_time = imu_msgs_.header.stamp;
    double d_theta = fabs((imu_msgs_.header.stamp - last_time).toSec()) * imu_msgs_.angular_velocity.z;
    last_time = imu_msgs_.header.stamp;
    return d_theta;
}

void UniversalNode::control_vel(const geometry_msgs::Twist cmd_vel) {
    drive_.SentRpm(cmd_vel);
}


