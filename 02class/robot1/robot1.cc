#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include <iostream>

using namespace cv;
using namespace std;
//3170406037 TORRE 电信172 2019.11.03

int main()
{
  Mat img, imgGray,result;
  img = imread("yuta.jpg");
  if (!img.data) {
      cout << "Please input image path" << endl;
      return 0;
  }
  imshow("原图", img);
  //img为原图，imgGray为灰度图
  cvtColor(img, imgGray, CV_BGR2GRAY);
  imshow("灰度图", imgGray);
  //blur(imgGray, imgGray, Size(3, 3));
  //imgGray为灰度图，result为二值图像
  //100~255为阈值，可以根据情况设定
  //在阈值中的像素点将变为0（白色部分），阈值之外的像素将变为1（黑色部分）
  threshold(imgGray, result, 100, 255, CV_THRESH_BINARY);
  imshow("二值化后的图", result);
  imwrite("二值化的二维码.jpg", result);
  cout << "图片已保存" << endl;
  waitKey();
 
  return 0;
}


