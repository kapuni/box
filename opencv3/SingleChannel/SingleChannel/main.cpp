#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

void CreatLookupTable(Mat &table)
{
	table.create(1, 256, CV_8UC1);

	uchar *p = table.data;

	for (int j = 0; j < 85; j++)
	{
		p[j] = 43;
	}
	for (int j = 85; j < 170; j++)
	{
		p[j] = 127;
	}
	for (int j = 170; j < 255; j++)
	{
		p[j] = 213;
	}

}

int main(int argc,char *acgv[])
	{
		Mat table;   //定义查找表
		Mat src = imread("F:/workspace/box/opencv3/image/cat4.jpg", IMREAD_GRAYSCALE);
		Mat dst;
		imshow("srcImage", src);
		CreatLookupTable(table);
		LUT(src, table, dst);   //LUT表示查找表
		imshow("dstImage", dst);
		waitKey(0);
		return 0;
	}