

#include "pch.h"
#include <opencv.hpp>

using namespace cv;

int main()
{
	Mat srcImage0 = imread("cat2.jpg");
	namedWindow("show0");
	imshow("show0", srcImage0);

	Mat srcImage1 = imread("cat1.jpg");
	namedWindow("show1");
	imshow("show1", srcImage1);

	Mat imageROI = srcImage0(Rect(750, 150, srcImage1.cols, srcImage1.rows)); //在srcImage0指定位置定义感兴趣区域ROI

	addWeighted(imageROI, 0.2, srcImage1, 0.8, 0, imageROI, -1); //叠加srcImage1到srcImage0的ROI区域

	namedWindow("show2");
	imshow("show2", srcImage0);

	waitKey(0);

	imwrite("test_add.jpg", srcImage0);//输出图像

	return 0;

}
