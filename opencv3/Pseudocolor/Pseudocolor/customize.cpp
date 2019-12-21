#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;

void CreatLookupTable(Mat&table)
{
	table.create(1, 256, CV_8UC3);

	uchar * p = table.data;

	for (int j = 0; j < 42; j++)
	{
		p[3 * j + 0] = 255 - j * 6;
		p[3 * j + 1] = 0;
		p[3 * j + 2] = 255;
	}
	for (int j = 43; j < 85; j++)
	{
		p[3 * j + 0] = 0;
		p[3 * j + 1] = 6*(j-43);
		p[3 * j + 2] = 255;
	}
	for (int j = 86; j < 127; j++)
	{
		p[3 * j + 0] = 0;
		p[3 * j + 1] = 255;
		p[3 * j + 2] = 255 - (j - 86) * 6;
	}
	for (int j = 128; j < 170; j++)
	{
		p[3 * j + 0] = (j-128) * 6;
		p[3 * j + 1] = 255;
		p[3 * j + 2] = 0;
	}
	for (int j = 171; j < 213; j++)
	{
		p[3 * j + 0] = 255;
		p[3 * j + 1] = 255-6*(j-171);
		p[3 * j + 2] = 0;
	}
	for (int j = 214; j < 255; j++)
	{
		p[3 * j + 0] = 255;
		p[3 * j + 1] = 0;
		p[3 * j + 2] = 6*(j-214);
	}
}

int main(int argc, char *argv[])
{
	Mat table;
	Mat src = imread("F:/workspace/box/opencv3/image/cat4.jpg");
	Mat dst;
	imshow("srcImage", src);
	CreatLookupTable(table);
	LUT(src, table, dst);
	imshow("dstImage", dst);
	waitKey(0);
	return 0;
}