#include <opencv2/opencv.hpp>
#include "opencv2/highgui.hpp"
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;
//3170406037 TORRE 电信172
int main( )
{
	//创建 grad_x 和 grad_y 矩阵
	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y,dst;
 
	Mat src = imread("yuta.jpg");
        if (!src.data) {
            cout << "Please input image path" << endl;
            return 0;
        }
	imshow("原图", src); 

	//求X方向梯度
	Sobel( src, grad_x, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT );
	convertScaleAbs( grad_x, abs_grad_x );
	imshow("X_Sobel", abs_grad_x); 

	//求Y方向梯度
	Sobel( src, grad_y, CV_16S, 0, 1, 3, 1, 1, BORDER_DEFAULT );
	convertScaleAbs( grad_y, abs_grad_y );
	imshow("Y_Sobel", abs_grad_y);

	//合并梯度
	addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst );
	imshow("SUM_Sobel", dst); 

	waitKey(0); 
	return 0; 
}

