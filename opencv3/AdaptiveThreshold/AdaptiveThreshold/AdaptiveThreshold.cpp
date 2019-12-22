#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat srcImage = imread("F:/workspace/box/opencv3/image/lena.jpg",IMREAD_GRAYSCALE);
	imshow("src", srcImage);

	Mat dstImage1;
	int maxVal = 255;
	int blockSize = 9;
	double C = 0;
	adaptiveThreshold(srcImage, dstImage1, maxVal, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, blockSize, C);

	imshow("dst:block=9", dstImage1);
	waitKey(0);

	return 0;
}