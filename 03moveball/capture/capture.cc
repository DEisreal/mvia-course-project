#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
    VideoCapture capture("ball play.mp4");
    //检测视频是否读取成功
    if (!capture.isOpened())
    {
        cout << "No input image";
        return 1;
    }

    //获取图像帧率
    double rate = capture.get(CV_CAP_PROP_FPS);
    bool stop = false;
    Mat frame;
    namedWindow("Example");

    int delay = 1000/rate;

    while (!stop)
    {
        if (!capture.read(frame))
            break;
        imshow("Example",frame);
        if (waitKey(delay) >= 0)
            stop = true;
    }
    return 0;
}

