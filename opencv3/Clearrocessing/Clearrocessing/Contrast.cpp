#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

const string trackName = "track";
int contrastValue;    //对比度值
int brightValue;     //亮度值
Mat srcImage;
Mat dstImage;

void trackbarCallback(int pos, void * data)
{
	//执行计算 g_dstImage (i,j) = a*g_srcImage(i,y) + b
	for (int y = 0; y < srcImage.rows; y++) {
		for (int x = 0; x < srcImage.cols; x++) {
			for (int c = 0; c < 3; c++)
			{
				dstImage.at<Vec3b>(y, x)[c] = saturate_cast<uchar>((contrastValue*0.01)*
					(srcImage.at<Vec3b>(y, x)[c]) + brightValue);
			}
		}
			
	}
	
	//显示图像
	imshow("srcImage", srcImage);
	imshow("dstImage", dstImage);

}

void contrastBrightImage()
{
	srcImage = imread("F:/workspace/box/opencv3/image/cat2.jpg");
	dstImage = Mat::zeros(srcImage.size(), srcImage.type());  //按照图像尺寸和类型初始化图像2
	contrastValue = 60;            //设置对比度
	brightValue = 60;            //设置亮度
	namedWindow("srcImage", 1);   //创建两个窗口来对比
	namedWindow("dstImage", 1);
	//创建滑条
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