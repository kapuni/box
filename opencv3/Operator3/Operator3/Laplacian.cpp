#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
/*
//使用Sobel算子对图像进行锐化

int main(int,char**argv)
{
	Mat src;
	Mat dst;

	src = imread("F:/workspace/box/opencv3/image/lena.jpg", 1);
	
	if (src.empty())
	{
		return -1;
	}

	Laplacian(src, dst, 0.3);

	imshow("srcImage", src);
	imshow("dstImage", dst);
	waitKey(0);

	return 0;
}
*/

//自定义Laplacian算子
int main(int, char**argv)
{
	Mat src;
	Mat dst;

	src = imread("F:/workspace/box/opencv3/image/lena.jpg", 1);

	if (src.empty())
	{
		return -1;
	}

	Mat kernel = (Mat_<float>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	filter2D(src, dst, CV_8UC3, kernel);

	imshow("srcImage", src);
	imshow("dstImage", dst);
	waitKey(0);

	return 0;
}