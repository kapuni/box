#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

int main()
{
	Mat srcImage = imread("F:/workspace/box/opencv3/image/lena.jpg");
	imshow("srcImage", srcImage);

	Rect ccmop;
	floodFill(srcImage, Point(100, 100), Scalar(255, 255, 255), &ccmop, Scalar(15, 15, 15), Scalar(15, 15, 15));

	imshow("dst", srcImage);
	waitKey(0);

	return 0;
}