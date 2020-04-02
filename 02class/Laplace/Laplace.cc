#include <opencv2/opencv.hpp>
#include "opencv2/highgui.hpp"
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;
//3170406037 TORRE 电信172
int main( )
{
	Mat src,src_gray,dst, abs_dst;
	src = imread("yuta.jpg");
        if (!src.data) {
            cout << "Please input image path" << endl;
            return 0;
        }
	imshow("原图", src); 
	//【1】使用高斯滤波消除噪声
	GaussianBlur( src, src, Size(3,3), 0, 0, BORDER_DEFAULT );
	//【2】转换为灰度图
	cvtColor( src, src_gray, CV_RGB2GRAY );
	//【3】使用Laplace函数
	Laplacian( src_gray, dst, CV_16S, 3, 1, 0, BORDER_DEFAULT );
	//【4】计算绝对值，并将结果转换成8位
	convertScaleAbs( dst, abs_dst );
	imshow( "Laplace变换", abs_dst );

	waitKey(0); 
	return 0; 

}

