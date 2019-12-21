#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
//全局变量声明
Mat g_srcImage, g_dst_Image1, g_dst_Image2, g_dst_Image3, g_dst_Image4;
int g_nBoxFilterPara = 5;      //方框滤波参数值
int g_nMeanBlurPara = 5;      //均值滤波参数值
int g_nGuassianBlurPara = 5; //高斯滤波参数值
int g_nMedianBlurPara = 5;   //中值滤波参数值

//全局函数声明回调函数
static void boxFilterCallback(int, void *);   //方框滤波
static void meanBlurCallback(int, void *);     //均值滤波
static void guassianBlurCallback(int, void *);  //高斯滤波
static void medianBlurCallback(int, void *);   //中值滤波

Mat addSaltNoise(const Mat srcImage, int n)   //加椒盐噪声
{
	Mat resultImage = srcImage.clone();
	for (int k = 0; k < n; k++)
	{
		//随机取值行列
		int i = rand() % resultImage.cols;
		int j = rand() % resultImage.rows;
		//图像通道判定
		if (resultImage.channels() == 1)
		{
			resultImage.at<uchar>(j, i) = 255;

		}
		else
		{
			resultImage.at<Vec3b>(j, i)[0] = 255;
			resultImage.at<Vec3b>(j, i)[1] = 255;
			resultImage.at<Vec3b>(j, i)[2] = 255;
		}
	}
	return resultImage;
}

int main(int argc, char *argv[])
{
	//载入原图
	Mat srcImage = imread("F:/workspace/box/opencv3/image/cat2.jpg");
	g_srcImage = addSaltNoise(srcImage, 5000);
	if (g_srcImage.empty())
	{
		printf("srcImage 错误!\n");
		return false;
	}

	g_dst_Image1 = g_srcImage.clone();
	g_dst_Image2 = g_srcImage.clone();
	g_dst_Image3 = g_srcImage.clone();
	g_dst_Image4 = g_srcImage.clone();

	//显示原图
	namedWindow("src", 1);
	imshow("src", srcImage);

	//显示噪声图
	namedWindow("srcAddNoise", 1);
	imshow("secAddNoise", g_srcImage);

	//方框滤波
	namedWindow("dstBoxFilter", 1);
	//创建轨迹条
	createTrackbar("Kernal Parameter: ", "dstBoxFilter", &g_nBoxFilterPara, 40, boxFilterCallback);
	boxFilterCallback(g_nBoxFilterPara, 0);
	imshow("dstBoxFilter", g_dst_Image1);

	//均值滤波
	namedWindow("dstMeanBlur", 1);
	createTrackbar("Kernal Parameter: ", "dstMeanBlur", &g_nMeanBlurPara, 40, meanBlurCallback);
	meanBlurCallback(g_nGuassianBlurPara, 0);

	//高斯滤波
	namedWindow("dstGaussianBlur", 1);
	createTrackbar("Kernal Parameter: ", "dstGaussianBlur", &g_nGuassianBlurPara, 40, guassianBlurCallback);
	guassianBlurCallback(g_nGuassianBlurPara, 0);

	//中值滤波
	namedWindow("dstMedianBlur", 1);
	createTrackbar("Kernal Parameter: ", "dstMedianBlur", &g_nMedianBlurPara, 40, medianBlurCallback);
	medianBlurCallback(g_nMedianBlurPara, 0);

	while (1)
	{
		waitKey(10);
	}

}

//方框滤波操作的回调函数
static void boxFilterCallback(int, void *)
{
	//方框滤波操作
	boxFilter(g_srcImage, g_dst_Image1, -1, Size(g_nBoxFilterPara + 1, g_nBoxFilterPara + 1), Point(-1, -1), false,
		BORDER_DEFAULT);
	//显示窗口
	imshow("dstBoxFilter", g_dst_Image1);
}

//均值滤波操作的回调函数
static void meanBlurCallback(int, void*)
{
	blur(g_srcImage, g_dst_Image2, Size(g_nMeanBlurPara+ 1, g_nMeanBlurPara + 1), Point(-1, -1));

	imshow("dstmeanFilter", g_dst_Image2);
}
//高斯滤波操作的回调函数
static void guassianBlurCallback(int, void *)
{
	GaussianBlur(g_srcImage, g_dst_Image3, Size(g_nGuassianBlurPara *2+1, g_nGuassianBlurPara *2+1), 0,0);

	imshow("dstGussianBlur", g_dst_Image3);
}
//中值滤波操作的回调函数
static void medianBlurCallback(int, void *)
{
	medianBlur(g_srcImage, g_dst_Image4, g_nMedianBlurPara);

	imshow("dstMedianBlur", g_dst_Image4);
}