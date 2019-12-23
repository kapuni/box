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

	std::vector<Mat>channels(3);  //定义vector
	split(src, channels);   //利用vector对象分离RGB

	Mat B, G, R;
	//按照BRG顺序
	B = channels[0];
	G = channels[1];
	R = channels[2];

	//三通道分别进行相同的锐化处理
	Mat B_sharp, G_sharp, R_sharp;
	Laplacian(B, B_sharp, CV_8UC1, 3, 1, 0, BORDER_DEFAULT);
	Laplacian(G, G_sharp, CV_8UC1, 3, 1, 0, BORDER_DEFAULT);
	Laplacian(R, R_sharp, CV_8UC1, 3, 1, 0, BORDER_DEFAULT);


	//融合锐化后的三通道
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