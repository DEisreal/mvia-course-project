#include <opencv2/opencv.hpp>
#include "opencv2/highgui.hpp"
#include <iostream>
#include <math.h>
 
using namespace cv;
using namespace std;
//3170406037 TORRE 电信172
int main( )
{
	Mat src,nny;
        src = imread("yuta.jpg");  
        if (!src.data) {
            cout << "Please input image path" << endl;
            return 0;
        }
	imshow("原图", src); 
	Mat src1=src.clone();
	//1、easy canny：拿到原图后直接用。
	Canny(src,nny,150,100,3);
	imshow("Canny1", nny); 

	//2、hard canny：转成灰度图，降噪，用canny，最后将得到的边缘作为掩码，拷贝原图到效果图上，得到彩色的边缘图
	Mat dst,edge,gray;
	// 创建与src同类型和大小的矩阵(dst)
	dst.create(src1.size(), src1.type());
	// 将原图像转换为灰度图像
	cvtColor(src1, gray, CV_BGR2GRAY);
	// 先用使用 3x3内核来降噪
	blur(gray, edge, Size(3,3));
	// 运行Canny算子
	Canny(edge, edge,3,9,3);
	//将g_dstImage内的所有元素设置为0 
	dst = Scalar::all(0);
	//使用Canny算子输出的边缘图g_cannyDetectedEdges作为掩码，来将原图g_srcImage拷到目标图g_dstImage中
	src1.copyTo(dst, edge);
	imshow("Canny2", dst); 

	waitKey(0); 
	return 0; 
}
