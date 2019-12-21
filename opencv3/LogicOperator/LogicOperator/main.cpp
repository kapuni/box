#include <opencv.hpp>

using namespace cv;

int main()
{
	Mat imageCircle = Mat::zeros(256, 256, CV_8UC3);   //256 X 256 ����ͨ����ֵͼ�� 
	Mat imageRect = Mat::zeros(256, 256, CV_8UC3);  //8λ3ͨ��

	circle(imageCircle, Point(127, 127), 100, Scalar(255, 255, 255), -1, 8, 0);   //��һ��Բ          ���������thicknessΪ-1��ʾ��ָ������ɫ���
	rectangle(imageRect, Rect(37, 37,180,180), Scalar(255, 255, 255), -1, 8, 0);//��������

	namedWindow("imageCircle");
	imshow("imageCircle", imageCircle);

	namedWindow("imageRect");
	imshow("imageRect", imageRect);

	Mat tempImage0 = Mat::zeros(256, 256, CV_8UC3);
	Mat tempImage1 = Mat::zeros(256, 256, CV_8UC3);
	Mat tempImage2 = Mat::zeros(256, 256, CV_8UC3);
	Mat tempImage3 = Mat::zeros(256, 256, CV_8UC3);

	tempImage0 = imageCircle & imageRect;
	tempImage1 = imageCircle | imageRect;
	tempImage2 = ~imageCircle;

	namedWindow("Image-ADD");
	imshow("Image-ADD", tempImage0);
	namedWindow("Image-OR");
	imshow("Image-OR", tempImage1);
	namedWindow("Image-NOT");
	imshow("Image-NOT", tempImage2);

	waitKey(0);
	return 0;
}