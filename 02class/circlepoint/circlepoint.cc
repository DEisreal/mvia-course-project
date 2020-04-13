#include <opencv2/opencv.hpp>
#include "opencv2/highgui.hpp"
#include <iostream>
#include <math.h>
#include <vector>

using namespace cv;
using namespace std;
//3170406037 TORRE 电信172
int main(int argc, char **argv) {
    Mat src = imread("egg.jpg");
    imshow("picture",src);
    if(src.empty())
    {
        cout << "can not open "  << endl;
        return -1;
    }
    Mat cimg;
    medianBlur(src, src, 5);
    cvtColor(src,cimg,COLOR_BGR2GRAY);
    GaussianBlur(cimg, cimg, Size(9, 9), 2, 2);
  //medianBlur(cimg, cimg, 5);
    Canny(cimg,cimg,10,250,5);
    imshow("canny",cimg);
    vector<Vec3f> circles;
    HoughCircles(cimg, circles, HOUGH_GRADIENT, 1, 30,100, 30, 10, 120);

    for (size_t i = 0; i < circles.size(); i++)
    {
       Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
       int radius = cvRound(circles[i][2]);
       //绘制圆心  
       circle(src, center, 3, Scalar(0, 0, 255), -1, 8, 0);
       //绘制圆轮廓 Scalar(B,G,R) RGB=173 255 47
       circle(src,center,radius,Scalar(47,255,173), 3, 8, 0);

       //横线
       Point pt1,pt2;
         pt1.x = cvRound(circles[i][0])+10;
         pt1.y = cvRound(circles[i][1]);
         pt2.x = cvRound(circles[i][0])-10;
         pt2.y = cvRound(circles[i][1]);
	line(src,pt1,pt2,CV_RGB(255,0,0),2,CV_AA,0);
       //竖线
       Point pt3,pt4;
         pt3.x = cvRound(circles[i][0]);
         pt3.y = cvRound(circles[i][1])+10;
         pt4.x = cvRound(circles[i][0]);
         pt4.y = cvRound(circles[i][1])-10;
	line(src,pt3,pt4,CV_RGB(255,0,0),2,CV_AA,0);
    }
    imshow("图片",src);
    imwrite("end.jpg",src);
    waitKey(0);
    return 0;
}

