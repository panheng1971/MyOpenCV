// MyOpenCV.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <opencv.hpp>
#include <opencv2/core/core.hpp>
#include <imgproc.hpp>
#include <imgcodecs.hpp>
#include <highgui/highgui.hpp>
using namespace std;

int g_slider_position = 0;
int g_run = 1, g_dontset = 0;//开始单步模式
cv::VideoCapture g_cap;

void onTrackbarSlide(int pos, void*) {
    g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);
    if (!g_dontset)
        g_run = 1;
    g_dontset = 0;
}

int main()
{

    //show a picture
    /*std::cout <<"这是潘恒的OpenCV程序for C++...";
    cv::Mat img = cv::imread("d:/bach.jpg", -1);
    if (img.empty()) return -1;
    cv::namedWindow("巴赫", cv::WINDOW_AUTOSIZE);
    cv::imshow("巴赫", img);
    cv:cvWaitKey(0);
    cv::destroyWindow("巴赫");
    return(0);*/


    //show a video
   //cv::namedWindow("video", cv::WND_PROP_AUTOSIZE);
   //g_cap.open("d:/robot.mp4");

   //
   //int frames = (int)g_cap.get(cv::CAP_PROP_FRAME_COUNT);
   //int tmpw = (int)g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
   //int tmph = (int)g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);
   //cv::createTrackbar("Position", "video", &g_slider_position, frames, onTrackbarSlide);
   //cv::Mat frame;
   //for (;;) {
   //   
   //    if (g_run != 0) {

   //        
   //        g_cap >> frame; if (frame.empty()) break;

   //        int current_pos = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);
   //        g_dontset = 1;

   //        cv::setTrackbarPos("Position", "video", current_pos);
   //        cv::imshow("video", frame);
   //        g_run -= 1;
   //    }
   //    char c = (char)cv::waitKey(10);
   //    if (c == 's')//singe step
   //    {
   //        g_run = 1;}
   //    if (c == 'r') {
   //        g_run = -1;}
   //    if (c == 27)
   //        break;
   //   
   //}

   //read video from camera

    cv::namedWindow("video", cv::WINDOW_AUTOSIZE);
    cv::VideoCapture cap;
    cap.open(0);
    cv::Mat frame;
    for (;;) {
        cap >> frame;
        if (frame.empty())break;
        cv::imshow("video", frame);
        if (cv::waitKey(33) >= 0) break;
    }

    return(0);
}

