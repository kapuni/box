#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

int main()
{
	Mat srcImage = imread("F:/workspace/box/opencv3/image/cat3.jpg");
	imshow("srcImage", srcImage);

	Mat dstImage;
	srcImage.copyTo(dstImage);

	cvtColor(srcImage, srcImage, COLOR_BGR2GRAY);
	int maxVal = 255;
	int blockSize = 149;
	double C = 0;
	adaptiveThreshold(srcImage, srcImage, maxVal, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, blockSize, C);

	imshow("dst-adaptiveThreshold", srcImage);
	std::vector<std::vector<Point>>contours ;
	std::vector<Vec4i>hierarchy;
	findContours(srcImage, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

	RNG rng(0);
	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(dstImage, contours, i, color, 2, 8, hierarchy, 0, Point(0, 0)); //»æÖÆÂÖÀª
		Rect rect = boundingRect(contours[i]);  //¼ì²âÍâÂÖÀª
		rectangle(dstImage, rect, Scalar(255, 0, 0), 3); //¶ÔÍâÂÖÀª¼Ó¾ØÐÎ¿ò


	}

	imshow("dst-Contours", dstImage);
	waitKey(0);

	return 0;
}