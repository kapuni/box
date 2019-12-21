#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

const string trackName = "track";
int contrastValue;    //�Աȶ�ֵ
int brightValue;     //����ֵ
Mat srcImage;
Mat dstImage;

void trackbarCallback(int pos, void * data)
{
	//ִ�м��� g_dstImage (i,j) = a*g_srcImage(i,y) + b
	for (int y = 0; y < srcImage.rows; y++) {
		for (int x = 0; x < srcImage.cols; x++) {
			for (int c = 0; c < 3; c++)
			{
				dstImage.at<Vec3b>(y, x)[c] = saturate_cast<uchar>((contrastValue*0.01)*
					(srcImage.at<Vec3b>(y, x)[c]) + brightValue);
			}
		}
			
	}
	
	//��ʾͼ��
	imshow("srcImage", srcImage);
	imshow("dstImage", dstImage);

}

void contrastBrightImage()
{
	srcImage = imread("F:/workspace/box/opencv3/image/cat2.jpg");
	dstImage = Mat::zeros(srcImage.size(), srcImage.type());  //����ͼ��ߴ�����ͳ�ʼ��ͼ��2
	contrastValue = 60;            //���öԱȶ�
	brightValue = 60;            //��������
	namedWindow("srcImage", 1);   //���������������Ա�
	namedWindow("dstImage", 1);
	//��������
	createTrackbar("Contrast", "dstImage", &contrastValue, 300, trackbarCallback);
	createTrackbar("Bright", "dstImage", &brightValue, 300, trackbarCallback);

	trackbarCallback(0, 0);
}

//int main()
//{
//	contrastBrightImage();
//
//	while (1)
//	{
//		waitKey(0);
//	}
//
//	return 0;
//}