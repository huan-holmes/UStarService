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

static int client_fd;

using namespace cv;
using namespace std;
int main(int argc, char **argv)
{
    ros::init(argc, argv, "image_socket");
    ROS_INFO("-----------------test");
    int sockfd;
    struct sockaddr_in serv_addr, client;
    //创建socket
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(PORT);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("Socket failed!\n");
        exit(1);
    }
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    {
        perror("bind serv_addr ");
        exit(1);
    }
    if (listen(sockfd, 10) == -1)
    {
        perror("listen::error");
    }
    else
    {
        printf("listening:...\n");
    }

    socklen_t sin_size = sizeof(struct sockaddr_in);
    if ((sockfd = accept(sockfd, (struct sockaddr *)&client, &sin_size)) == -1)
    {
        perror("accept:");
        return -1;
    }
    else
    {
        printf("accept successful!\r\n");
    }
    int recLen = 0;
    Mat image = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);
    char buffer[BUFFER_SIZE] = {0};
    while (1)
    {
        memset(buffer, 0, sizeof(buffer));
        if ((recLen = recv(sockfd, buffer, BUFFER_SIZE, 0)) == -1)
        {
            perror("recv:");
        }
        else
        {
            if (recLen > 0)
            {
                recLen = 0;
                printf("Receive a message:%s\r\n", buffer);
                vector<uchar> data_encode;
                vector<int> quality = vector<int>(2);
                quality[0] = CV_IMWRITE_JPEG_QUALITY;
                quality[1] = 50;
                imencode(".jpg", image, data_encode, quality); //将图像编码
                //char encodeImg[655350];
                int nSize = data_encode.size();
                std::cout << "图像的数据： " << nSize << endl;
                // write(sockfd, reinterpret_cast<uchar*>(&nSize), sizeof(int));
                sendto(sockfd, &data_encode[0], nSize, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
            }
        }
    }
    close(sockfd);
    ROS_INFO("No error.");
    return 0;
}