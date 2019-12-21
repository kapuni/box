
#include "pch.h"
#include <opencv.hpp>

using namespace cv;

int main()
{
	int degree = 45;
	Mat srcImage = imread("F:\\workspace\\box\\opencv3\\image\\cat1.jpg");
	Mat dsImage;
	imshow("cat1", srcImage);
	//旋转中心为图像中心
	Point2f center;
	center.x = float(srcImage.cols / 2.0 + 0.5);
	center.y = float(srcImage.rows / 2.0 + 0.5);
	//计算二维旋转的仿射变换矩阵
	Mat M;
	M = getRotationMatrix2D(center, degree, 0.7);
	//变换图像，用黑色填充
	warpAffine(srcImage, dsImage, M, dsImage.size());
	imshow("dsImage", dsImage);
	waitKey(0);
	return 0;

}