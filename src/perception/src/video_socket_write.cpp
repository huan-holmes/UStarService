//Includes all the headers necessary to use the most common public pieces of the ROS system.
#include <ros/ros.h>
//Use image_transport for publishing and subscribing to images in ROS
#include <image_transport/image_transport.h>
//Use cv_bridge to convert between ROS and OpenCV Image formats
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
//Include headers for OpenCV Image processing
#include <opencv-3.3.1-dev/opencv2/imgproc/imgproc.hpp>
//Include headers for OpenCV GUI handling
#include <opencv-3.3.1-dev/opencv2/highgui/highgui.hpp>
#include <opencv-3.3.1-dev/opencv2/core.hpp>
#include <opencv-3.3.1-dev/opencv2/opencv.hpp>
#include <std_msgs/UInt8.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <sys/ioctl.h>

using namespace cv;
using namespace std;

//Store all constants for image encodings in the enc namespace to be used later.  
//namespace enc = sensor_msgs::image_encodings;

static int sockfd;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "image_socket");
    ROS_INFO("-----------------");
    struct sockaddr_in serv_addr;
    //创建socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        perror("Socket failed!\n");
        exit(1);
    }
    printf("Socket id = %d\n", sockfd);
    //设置sockaddr_in 结构体中相关参数
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(10000);
    serv_addr.sin_addr.s_addr = inet_addr("192.168.0.101");
    //inet_pton(AF_INET, servInetAddr, &serv_addr.sin_addr);
    bzero(&(serv_addr.sin_zero), 8);
    //调用connect 函数主动发起对服务器端的连接
    /*
    if(connect(sockfd,(struct sockaddr *)&serv_addr, sizeof(serv_addr))== -1)
    {
        perror("Connect failed!\n");
        exit(1);
    }
    printf("welcome\n");
*/
    ros::NodeHandle nh;
    //image_transport::ImageTransport it(nh);

    //image_transport::Subscriber sub = it.subscribe("/usb_cam/image_raw", 1, imageCallback);
    //ros::Subscriber camInfo= nh.subscribe("/usb_cam/camera_info", 1, camInfoCallback);
    //ros::Rate loop_rate(100);
    VideoCapture capture(0);
    Mat image;

    while (1)
    {
        if (!capture.isOpened())
            return 0;

        capture >> image;
        imshow("client_send_video", image);
        waitKey(3);
        if (image.empty())
            continue;
        /*
        vector<uchar> data_encode;
        vector<int>param =vector<int>(2);
        param[0]=CV_IMWRITE_JPEG_QUALITY;
        param[1]=90;
        imencode(".jpg", image, data_encode,param);
        int nSize=data_encode.size();
        char buff[1];
        buff[0]=nSize;
        write(sockfd, buff, 1);
        if (write(sockfd, &data_encode[0], nSize) < 0)
        {
            printf("send image1 error: %s(errno: %d)\n", strerror(errno), errno);
            return -1;
        }
*/
        /*
        //可行
        vector<uchar> data_encode;
        vector<int>quality =vector<int>(2);
        quality[0]=CV_IMWRITE_JPEG_QUALITY;
        quality[1]=90;
        //vector<int>quality;
        //quality.push_back(CV_IMWRITE_JPEG_QUALITY);
        //quality.push_back(50);//进行50%的压缩
        imencode(".jpg", image, data_encode,quality);//将图像编码
        char encodeImg[655350];
        int nSize=data_encode.size();
        for (int i = 0; i < nSize; i++)
        {
            encodeImg[i] = data_encode[i];
        }

        if (write(sockfd, encodeImg, nSize) < 0)
        {
            printf("send image1 error: %s(errno: %d)\n", strerror(errno), errno);
            return -1;
        }

        memset(encodeImg, 0, sizeof(encodeImg));
*/

        vector<uchar> data_encode;
        vector<int> quality = vector<int>(2);
        quality[0] = CV_IMWRITE_JPEG_QUALITY;
        quality[1] = 50;
        imencode(".jpg", image, data_encode, quality); //将图像编码
        //char encodeImg[655350];
        int nSize = data_encode.size();
        cout << "图像的数据： " << nSize << endl;
        // write(sockfd, reinterpret_cast<uchar*>(&nSize), sizeof(int));
        sendto(sockfd, &data_encode[0], nSize, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
        /*
        if (write(sockfd, &data_encode[0], nSize) < 0)
        {
            printf("send image1 error: %s(errno: %d)\n", strerror(errno), errno);
            return -1;
        }
        */
        //memset(encodeImg, 0, sizeof(encodeImg));
    }
    close(sockfd);
    ROS_INFO("No error.");
    return 0;
}
