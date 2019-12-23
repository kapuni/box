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

	std::vector<Mat>channels(3);  //定义vector
	split(src, channels);   //利用vector对象分离RGB

	//求原图像的RGB分量的均值
	double B, G, R;
	B = mean(channels[0])[0];
	G = mean(channels[1])[0];
	R = mean(channels[2])[0];

	//需要调整的RGB分量的增益
	double KR, KG, KB;
	KB = (R + G + B) / (3 * B);
	KG = (R + G + B) / (3 * G);
	KR = (R + G + B) / (3 * R);

	//调整RGB的3通道各自的值
	channels[0] = channels[0] * KB;
	channels[1] = channels[1] * KG;
	channels[2] = channels[2] * KR;
	//RGB三通道图像合并
	merge(channels, dst);


	imshow("srcImage", src);
	imshow("dstImage", dst);

	waitKey(0);

	return 0;

}