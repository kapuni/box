#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

int main(int, char**argv)
{
	Mat src;
	Mat tmp;
	Mat dst;

	src = imread("F:/workspace/box/opencv3/image/lena.jpg", 1);

	if (src.empty())
	{
		return -1;
	}

	std::vector<Mat>channels(3);  //����vector
	split(src, channels);   //����vector�������RGB

	//��ԭͼ���RGB�����ľ�ֵ
	double B, G, R;
	B = mean(channels[0])[0];
	G = mean(channels[1])[0];
	R = mean(channels[2])[0];

	//��Ҫ������RGB����������
	double KR, KG, KB;
	KB = (R + G + B) / (3 * B);
	KG = (R + G + B) / (3 * G);
	KR = (R + G + B) / (3 * R);

	//����RGB��3ͨ�����Ե�ֵ
	channels[0] = channels[0] * KB;
	channels[1] = channels[1] * KG;
	channels[2] = channels[2] * KR;
	//RGB��ͨ��ͼ��ϲ�
	merge(channels, dst);


	imshow("srcImage", src);
	imshow("dstImage", dst);

	waitKey(0);

	return 0;

}