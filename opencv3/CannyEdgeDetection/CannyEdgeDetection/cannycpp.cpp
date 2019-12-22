#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcImage = imread("F:/workspace/box/opencv3/image/lena.jpg");
	imshow("src", srcImage);

	Mat grayImage;
	cvtColor(srcImage, grayImage, CV_BGR2GRAY);

	Mat midImage;
	grayImage.copyTo(midImage);

	bilateralFilter(midImage, grayImage, 7, 14, 4);
	imshow("dst0", midImage);
	imshow("dst1", grayImage);
	Mat cannyImage;
	double g_nCurrValue = 12;
	double g_nP = 2;
	Canny(grayImage, cannyImage, (double) g_nCurrValue, (double)((g_nCurrValue + 1)*(2 + g_nP / 100.0)), 3);
	imshow("dst2", cannyImage);
	waitKey(0);

	return 0;

}