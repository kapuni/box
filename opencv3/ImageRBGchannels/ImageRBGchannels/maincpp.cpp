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
	split(srcImage0, src0rgbChannels);  //������ͨ��

	vector<Mat>src1rgbChannels(3);
	split(srcImage1, src1rgbChannels);  //�ڶ�������������Mat���׵�ַ����verctor<Mat>����
	//����srcImage0��srcImage1�ĵ���ͨ��
	addWeighted(src0rgbChannels[2], 0.5, src1rgbChannels[2], 0.5, 0, src1rgbChannels[2], -1);
	src1rgbChannels[0] = Mat::zeros(src0rgbChannels[0].size(), src1rgbChannels[0].type());         //srcImage1 ͨ��0��������
	src1rgbChannels[1] = Mat::zeros(src0rgbChannels[1].size(), src1rgbChannels[1].type());         //srcImage1 ͨ��1��������

	merge(src1rgbChannels, dsImage1);  //�ϲ���ͨ��

	namedWindow("show2");
	imshow("show2", dsImage1);

	waitKey(0);
	return 0;
}