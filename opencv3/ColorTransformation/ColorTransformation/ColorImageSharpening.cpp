#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

/*
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

	Mat B, G, R;
	//����BRG˳��
	B = channels[0];
	G = channels[1];
	R = channels[2];

	//��ͨ���ֱ������ͬ���񻯴���
	Mat B_sharp, G_sharp, R_sharp;
	Laplacian(B, B_sharp, CV_8UC1, 3, 1, 0, BORDER_DEFAULT);
	Laplacian(G, G_sharp, CV_8UC1, 3, 1, 0, BORDER_DEFAULT);
	Laplacian(R, R_sharp, CV_8UC1, 3, 1, 0, BORDER_DEFAULT);


	//�ں��񻯺����ͨ��
	std::vector<Mat>channels_sharp;
	channels_sharp.push_back(B_sharp);
	channels_sharp.push_back(G_sharp);
	channels_sharp.push_back(R_sharp);
	merge(channels_sharp, dst);


	imshow("srcImage", src);
	imshow("dstImage", dst);

	waitKey(0);

	return 0;

}
*/