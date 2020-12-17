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
#include <stdio.h>
#include <ros/ros.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <signal.h>
#define PORT 1234
#define BUFFER_SIZE 1500
static int sockfd;
static int client_fd;

using namespace cv;
using namespace std;
int main(int argc, char **argv)
{
    ros::init(argc, argv, "image_socket");
    ROS_INFO("-----------------test");
    struct sockaddr_in serv_addr, client;
    //创建socket 
    bzero(&serv_addr,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(PORT);
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1)
    {
        perror("Socket failed!\n");
        exit(1);
    }
    if(bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))==-1){
        perror("bind serv_addr ");
        exit(1);
    }
    sockaddr clntAddr;
    listen(sockfd, 20);

   // Mat image = cv::imread(argv[1],CV_LOAD_IMAGE_COLOR);
    char buffer[BUFFER_SIZE] = {0};
    while (1)
    {
        ROS_INFO("working!");
        //int addr_len = sizeof(client);
        //int clntSock = accept(sockfd, (sockaddr*)&clntAddr, &addr_len);
        socklen_t client_len;
        client_len=sizeof(client_fd);
        int recvRe = recvfrom(sockfd, buffer,BUFFER_SIZE, 0, (struct sockaddr*)&client_fd,&client_len);
        //ROS_INFO_STREAM(clntAddr.sa_data);
        // if (image.empty())
        //     continue;
        //int clntSock = accept(sockfd, (sockaddr*)&clntAddr, &nSize);
        //int ret = recv(sockfd,buffer,BUFFER_SIZE,0);
        //send(sockfd, buffer, ret, 0); //将数据原样返回
        // if(ret == -1){
        //    perror("recvfrom error: ");
        //    exit(1);
        // }
        // if (ret == -1)
        //     continue;
        // std::cout << buffer <<endl;
        // vector<uchar> data_encode;
        // vector<int> quality = vector<int>(2);
        // quality[0] = CV_IMWRITE_JPEG_QUALITY;
        // quality[1] = 50;
        // imencode(".jpg", image, data_encode, quality); //将图像编码
        // //char encodeImg[655350];
        // int nSize = data_encode.size();
        // std::cout << "图像的数据： " << nSize << endl;
        // // write(sockfd, reinterpret_cast<uchar*>(&nSize), sizeof(int));
        // sendto(sockfd, &data_encode[0], nSize, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    }
    close(sockfd);
    ROS_INFO("No error.");
    return 0;
}