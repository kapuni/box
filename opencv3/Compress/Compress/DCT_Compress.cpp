#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <math.h>
#include <cv.h>
#include <iostream>

using namespace std;
using namespace cv;

double T = 40;

int main()
{
	Mat src = imread("F:\\workspace\\box\\opencv3\\image\\lena.bmp", 1);
	imshow("OriginImage", src);

	int h = src.rows;
	int w = src.cols;

	//从BGR空间转换到YUV空间（也可直接在RGB空间）
	Mat yuvimg(src.size(), CV_8UC3);
	cvtColor(src, yuvimg, CV_BGR2YUV);
	Mat dst(src.size(), CV_64FC3);

	//分割YUV通道
	vector<Mat>channels;
	split(yuvimg, channels);


	//提取YUV颜色空间各通道
	Mat Y = channels.at(0); imshow("Y image", Y);
	Mat U = channels.at(1); imshow("U image", U);
	Mat V = channels.at(2); imshow("V image", V);

	//DCT系数的三个通道
	Mat DCTY(src.size(), CV_64FC1);
	Mat DCTU(src.size(), CV_64FC1);
	Mat DCTV(src.size(), CV_64FC1);

	//DCT变换
	dct(Mat_<double>(Y), DCTY);
	dct(Mat_<double>(U), DCTU);
	dct(Mat_<double>(V), DCTV);

	//Y通道压缩
	for (int i = 0; i < h; i++)
	{
		double *p = DCTY.ptr<double>(i);
		for (int j = 0; j < w; j++)
		{
			if (abs(p[j]) < T)
				p[j] = 0;
		}
	}
	//U通道压缩
	for (int i = 0; i < h; i++)
	{
		double *p = DCTU.ptr<double>(i);
		for (int j = 0; j < w; j++)
		{
			if (abs(p[j]) < T)
				p[j] = 0;
		}
	}
	//V通道压缩
	for (int i = 0; i < h; i++)
	{
		double *p = DCTV.ptr<double>(i);
		for (int j = 0; j < w; j++)
		{
			if (abs(p[j]) < T)
				p[j] = 0;
		}
	}

	Mat dstY(src.size(), CV_64FC1);
	Mat dstU(src.size(), CV_64FC1);
	Mat dstV(src.size(), CV_64FC1);

	//DCT逆变换
	idct(DCTY, dstY);
	idct(DCTU, dstU);
	idct(DCTV, dstV);

	//merge方式一
	/*Mat planes[] = { Mat_<uchar>(dstB),Mat_<uchar>(dstG) ,Mat_<uchar>(dstR) };
	merge(planes, 3, yuvimg);
	cvtColor(yuvimg, dst, CV_YUV2BGR);*/

	//merge方式二
	channels.at(0) = Mat_<uchar>(dstY);
	channels.at(1) = Mat_<uchar>(dstU);
	channels.at(2) = Mat_<uchar>(dstV);
	merge(channels, yuvimg);

	//将压缩后的图像从YUV空间转换到RGB空间
	cvtColor(yuvimg, dst, CV_YUV2BGR);

	imshow("Recovered Y image", Mat_<uchar>(dstY));
	imshow("Recovered U image", Mat_<uchar>(dstU));
	imshow("Recovered V image", Mat_<uchar>(dstV));
	imshow("DstImage", dst);

	waitKey(0);
	return 0;
}