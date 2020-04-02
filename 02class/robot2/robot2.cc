#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include <iostream>

using namespace cv;
using namespace std;
//3170406037 TORRE 电信172 2019.11.03

int main(){
	//0表示将图像转换为灰度再返回
	Mat srcImage = imread("yuta.jpg", 0);
	imshow("原图",srcImage);
	if(!srcImage.data) {cout << "fail to load image" << endl;
 	return 0;} 	
        //定义变量
	Mat dstHist;
       	int dims = 1;
	float hranges[] = {0, 256};
	const float *ranges[] = {hranges};   // 这里需要为const类型
	int size = 256;	int channels = 0;
 	//计算图像的直方图
	calcHist(&srcImage, 1, &channels, Mat(), dstHist, dims, &size, ranges);
    	Mat dstImage(size, size, CV_8U, Scalar(0));
	//获取最大值和最小值
	double minValue = 0;
	double maxValue = 0;
	minMaxLoc(dstHist,&minValue, &maxValue, 0, 0);  //  在cv中用的是cvGetMinMaxHistValue
 	//绘制出直方图
	//saturate_cast函数的作用即是：当运算完之后，结果为负，则转为0，结果超出255，则为255。
	int hpt = saturate_cast<int>(0.9 * size);
	for(int i = 0; i < 256; i++)
	{
		float binValue = dstHist.at<float>(i);//   注意hist中是float类型
   		//拉伸到0-max
		int realValue = saturate_cast<int>(binValue * hpt/maxValue);
		line(dstImage,Point(i, size - 1),Point(i, size - realValue),Scalar(255));
	}
	imshow("直方图", dstImage);
	waitKey(0);
	return 0;
}

