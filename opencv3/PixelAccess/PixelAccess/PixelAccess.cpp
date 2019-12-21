
#include "pch.h"
#include <opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	//原始图像初始化
	Mat image(240, 240, CV_8UC3, Scalar(0, 0, 0));
	imshow("srcImage", image);
	
	//----------------指针操作--------------------
	double start = static_cast<double>(getTickCount());

	int rowNumber = image.rows;                    //行数
	int colNumber = image.cols * image.channels();  //每一行元素个数= 列数 X 通道数
	for (int i = 0; i < rowNumber; i++)           //行循环
	{
		uchar*data = image.ptr<uchar>(i);          //获取第i行的首地址
		for (int j = 0; j < colNumber; j++)       //列循环
		{
			//开始处理
			data[j] = 255;
		}
	}

	double end = static_cast<double>(getTickCount());
	double time = (end - start) / getTickFrequency();
	cout << "The Method 1 runs " << time << " seconds." << endl;
	imshow("Method1", image);
	//---------------------------------------------

	//----------------迭代器操作------------------
	start = static_cast<double>(getTickCount());

	Mat_<Vec3b>::iterator it = image.begin<Vec3b>();     //初始位置的迭代器
	Mat_<Vec3b>::iterator itend = image.end<Vec3b>();    //终止位置的迭代器
	for (; it != itend; it++)
	{
		//处理RGB三通道
		(*it)[0] = 255;  //B
		(*it)[1] = 255;  //G
		(*it)[2] = 0;    //R
	}

	end = static_cast<double>(getTickCount());
	time = (end - start) / getTickFrequency();     //计算时间
	cout << "The Method 2 runs " << time << " seconds.\n";
	imshow("Method2", image);
	//------------------------------------------

	//----------------动态地址计算------------------
	start = static_cast<double>(getTickCount());

	rowNumber = image.rows;
	colNumber = image.cols;
	for (int i= 0;i<rowNumber;i++)
		for (int j = 0; j < colNumber; j++)
		{
			//同上
			(*it)[0] = 255;
			(*it)[1] = 255;
			(*it)[2] = 0;
		}

	end = static_cast<double>(getTickCount());
	time = (end - start) / getTickFrequency();
	cout << "The Method 3 runs " << time << " seconds.\n";
	imshow("Method3", image);
	//------------------------------------------



	cvWaitKey(0);
	return 1;
}

//结果
//The Method 1 runs 0.0006916 seconds.
//The Method 2 runs 0.0273789 seconds.
//The Method 3 runs 0.0093099 seconds.