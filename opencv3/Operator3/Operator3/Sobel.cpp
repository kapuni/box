/*
	使用Sobel算子对图像进行锐化
*/

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

//int main(int, char**argv)
//{
//	Mat src;
//	Mat grad;
//	int scale = 1;
//	int delta = 0;
//	int ddepth = CV_16S;
//
//	src = imread("F:/workspace/box/opencv3/image/lena.jpg", IMREAD_GRAYSCALE);
//
//	if (src.empty())
//	{
//		return -1;
//	}
//
//	Mat grad_x, grad_y;
//	Mat abs_grad_x, abs_grad_y;
//
//	Sobel(src, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);
//	Sobel(src, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT);
//	convertScaleAbs(grad_x, abs_grad_x);
//	convertScaleAbs(grad_y, abs_grad_y);
//	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);
//
//	imshow("srcImage", src);
//	imshow("dstImage", grad);
//	waitKey(0);
//
//	return 0;
//}