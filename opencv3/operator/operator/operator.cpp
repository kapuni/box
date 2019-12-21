
#include "pch.h"
#include <opencv.hpp>

using namespace cv;

//resize
/*
int main()
{
	Mat srcImage = imread("cat.jpg");
	Mat dsImage;
	imshow("srcImage", srcImage);
	resize(srcImage, dsImage, cvSize(256, 256), 0, 0, INTER_LINEAR);
	imshow("dsImage", dsImage);
	waitKey(0);
	return 0;
}
*/

//金字塔法等比例缩放
int main()
{
	Mat srcImage = imread("cat.jpg");
	Mat dsImage0,dsImage1;
	imshow("srcImage", srcImage);
	pyrUp(srcImage, dsImage0, Size(srcImage.cols * 2, srcImage.rows * 2));
	pyrDown(srcImage, dsImage1, Size(srcImage.cols / 2, srcImage.rows / 2));
	imshow("dsImage0", dsImage0);
	imshow("dsImage1", dsImage1);
	waitKey(0);
	return 0;
}