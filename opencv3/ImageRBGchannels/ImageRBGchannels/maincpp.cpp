#include<opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat srcImage0 = imread("F:/workspace/box/opencv3/image/cat2.jpg");
	namedWindow("show0");
	imshow("show0", srcImage0);

	Mat srcImage1 = imread("F:/workspace/box/opencv3/image/cat3.jpg");
	namedWindow("show1");
	imshow("show1", srcImage1);

	Mat dsImage0, dsImage1;
	vector<Mat>src0rgbChannels(3);
	split(srcImage0, src0rgbChannels);  //分离三通道

	vector<Mat>src1rgbChannels(3);
	split(srcImage1, src1rgbChannels);  //第二个参数可以是Mat的首地址或者verctor<Mat>对象
	//叠加srcImage0和srcImage1的第三通道
	addWeighted(src0rgbChannels[2], 0.5, src1rgbChannels[2], 0.5, 0, src1rgbChannels[2], -1);
	src1rgbChannels[0] = Mat::zeros(src0rgbChannels[0].size(), src1rgbChannels[0].type());         //srcImage1 通道0数据清零
	src1rgbChannels[1] = Mat::zeros(src0rgbChannels[1].size(), src1rgbChannels[1].type());         //srcImage1 通道1数据清零

	merge(src1rgbChannels, dsImage1);  //合并三通道

	namedWindow("show2");
	imshow("show2", dsImage1);

	waitKey(0);
	return 0;
}