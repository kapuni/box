#include <opencv.hpp>
using namespace cv;

int main()
{
	Mat srcImage0 = imread("F:/workspace/box/opencv3/image/cat2.jpg");
	namedWindow("show0");
	imshow("show0", srcImage0);

	Mat srcImage1 = imread("F:/workspace/box/opencv3/image/cat3.jpg");
	namedWindow("show1");
	imshow("show1", srcImage1);

	Mat dsImage;
	addWeighted(srcImage0, 0.2, srcImage1, 0.8, 0, dsImage, -1);

	namedWindow("show2");
	imshow("show2", dsImage);
	waitKey(0);

	imwrite("F:/workspace/box/opencv3/image/cat_add.jpg", dsImage);
	
	return 0;

}