#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;

//int main(int argc, char *argv[])
//{
//	Mat image = imread("F:/workspace/box/opencv3/image/cat4.jpg");
//
//	imshow("srcImage", image);
//	Mat imageColor[12];
//	for (int i = 0; i < 12; i++)
//	{
//		applyColorMap(image, imageColor[i], i);
//		imshow("dstImage", imageColor[i]);
//		waitKey(0);
//	}
//	return 0;
//}