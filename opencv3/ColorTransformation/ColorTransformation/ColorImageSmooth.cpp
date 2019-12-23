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
	split(src, channels);

	Mat B, G, R;

	B = channels[0];
	G = channels[1];
	R = channels[2];

	//三通道分别进行相同的平滑处理
	Mat B_smooth, G_smooth, R_smooth;
	blur(B, B_smooth, Size(3, 3));
	blur(G, G_smooth, Size(3, 3));
	blur(R, R_smooth, Size(3, 3));

	//融合平滑后的三通道
	std::vector<Mat>channels_smooth;
	channels_smooth.push_back(B_smooth);
	channels_smooth.push_back(G_smooth);
	channels_smooth.push_back(R_smooth);
	merge(channels_smooth, dst);
	

	imshow("srcImage", src);
	imshow("dstImage", dst);

	waitKey(0);

	return 0;

}*/