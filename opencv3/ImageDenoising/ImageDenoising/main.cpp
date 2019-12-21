#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
//ȫ�ֱ�������
Mat g_srcImage, g_dst_Image1, g_dst_Image2, g_dst_Image3, g_dst_Image4;
int g_nBoxFilterPara = 5;      //�����˲�����ֵ
int g_nMeanBlurPara = 5;      //��ֵ�˲�����ֵ
int g_nGuassianBlurPara = 5; //��˹�˲�����ֵ
int g_nMedianBlurPara = 5;   //��ֵ�˲�����ֵ

//ȫ�ֺ��������ص�����
static void boxFilterCallback(int, void *);   //�����˲�
static void meanBlurCallback(int, void *);     //��ֵ�˲�
static void guassianBlurCallback(int, void *);  //��˹�˲�
static void medianBlurCallback(int, void *);   //��ֵ�˲�

Mat addSaltNoise(const Mat srcImage, int n)   //�ӽ�������
{
	Mat resultImage = srcImage.clone();
	for (int k = 0; k < n; k++)
	{
		//���ȡֵ����
		int i = rand() % resultImage.cols;
		int j = rand() % resultImage.rows;
		//ͼ��ͨ���ж�
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
	//����ԭͼ
	Mat srcImage = imread("F:/workspace/box/opencv3/image/cat2.jpg");
	g_srcImage = addSaltNoise(srcImage, 5000);
	if (g_srcImage.empty())
	{
		printf("srcImage ����!\n");
		return false;
	}

	g_dst_Image1 = g_srcImage.clone();
	g_dst_Image2 = g_srcImage.clone();
	g_dst_Image3 = g_srcImage.clone();
	g_dst_Image4 = g_srcImage.clone();

	//��ʾԭͼ
	namedWindow("src", 1);
	imshow("src", srcImage);

	//��ʾ����ͼ
	namedWindow("srcAddNoise", 1);
	imshow("secAddNoise", g_srcImage);

	//�����˲�
	namedWindow("dstBoxFilter", 1);
	//�����켣��
	createTrackbar("Kernal Parameter: ", "dstBoxFilter", &g_nBoxFilterPara, 40, boxFilterCallback);
	boxFilterCallback(g_nBoxFilterPara, 0);
	imshow("dstBoxFilter", g_dst_Image1);

	//��ֵ�˲�
	namedWindow("dstMeanBlur", 1);
	createTrackbar("Kernal Parameter: ", "dstMeanBlur", &g_nMeanBlurPara, 40, meanBlurCallback);
	meanBlurCallback(g_nGuassianBlurPara, 0);

	//��˹�˲�
	namedWindow("dstGaussianBlur", 1);
	createTrackbar("Kernal Parameter: ", "dstGaussianBlur", &g_nGuassianBlurPara, 40, guassianBlurCallback);
	guassianBlurCallback(g_nGuassianBlurPara, 0);

	//��ֵ�˲�
	namedWindow("dstMedianBlur", 1);
	createTrackbar("Kernal Parameter: ", "dstMedianBlur", &g_nMedianBlurPara, 40, medianBlurCallback);
	medianBlurCallback(g_nMedianBlurPara, 0);

	while (1)
	{
		waitKey(10);
	}

}

//�����˲������Ļص�����
static void boxFilterCallback(int, void *)
{
	//�����˲�����
	boxFilter(g_srcImage, g_dst_Image1, -1, Size(g_nBoxFilterPara + 1, g_nBoxFilterPara + 1), Point(-1, -1), false,
		BORDER_DEFAULT);
	//��ʾ����
	imshow("dstBoxFilter", g_dst_Image1);
}

//��ֵ�˲������Ļص�����
static void meanBlurCallback(int, void*)
{
	blur(g_srcImage, g_dst_Image2, Size(g_nMeanBlurPara+ 1, g_nMeanBlurPara + 1), Point(-1, -1));

	imshow("dstmeanFilter", g_dst_Image2);
}
//��˹�˲������Ļص�����
static void guassianBlurCallback(int, void *)
{
	GaussianBlur(g_srcImage, g_dst_Image3, Size(g_nGuassianBlurPara *2+1, g_nGuassianBlurPara *2+1), 0,0);

	imshow("dstGussianBlur", g_dst_Image3);
}
//��ֵ�˲������Ļص�����
static void medianBlurCallback(int, void *)
{
	medianBlur(g_srcImage, g_dst_Image4, g_nMedianBlurPara);

	imshow("dstMedianBlur", g_dst_Image4);
}