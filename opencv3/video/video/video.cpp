
#include "pch.h"
#include <opencv.hpp>
using namespace cv;

int main()
{
	//VideoCapture myCapture("cross.avi"); //视频实例化和初始化  
	//VideoCapture myCapture；
	//myCapture.open("cross.avi")；
	VideoCapture myCapture(0);  //初始化的"cross.avi" 改为 0 ，调用摄像头
	VideoWriter myVideoWriter;
	myVideoWriter.open(
		"F:\\myvideo.avi",              //输出文件名
		CV_FOURCC('D', 'I', 'V', 'X'),  //视屏编码类型，手动选择视频编码类型，如果为-1表示跳出选择窗口进行选择
		30.0,    //帧率（FPS）
		cv::Size(640, 480), //单帧图像分辨率 640x480
		true               //只输入彩色图
	);
	namedWindow("show", WINDOW_NORMAL);  //namedWindow("show", 0)  第二个参数 窗口可调
	int i = 0;
	while (i<100)  //创建循环，每次循环读1帧
	{
		i++;
		Mat myFrame;    //储存1帧图像
		myCapture >> myFrame;//从视频序列取出一张图像到myFrame

		if (myFrame.empty()) //储存图像帧为空，则视频播放结束
		{
			break;
		}
		imshow("show", myFrame); //显示当前帧
		//myVideoWriter << myFrame;
		myVideoWriter.write(myFrame); //当前帧写入
		waitKey(30);  //延迟30毫秒
	}
	myCapture.release();
	myVideoWriter.release();
	return 0;
}