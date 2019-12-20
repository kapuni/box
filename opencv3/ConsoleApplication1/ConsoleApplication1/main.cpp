
#include "pch.h"
#include <opencv.hpp>
using namespace cv;

int main()
{
	Mat srcImage = imread("cat1.jpg");
	namedWindow("show");
	imshow("show", srcImage);
	waitKey(0);
	return 0;
}



