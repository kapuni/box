#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
/*
int main(int,char ** argv)
{
	Mat src;
	Mat tmp;
	Mat dst;

	src = imread("F:\\workspace\\box\\opencv3\\image\\lena.bmp", 1);
	
	if (src.empty())
	{
		return -1;
	}

	std::vector<int> compression_params;
	compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);  //—°‘ÒJPEP—πÀı
	compression_params.push_back(10);                     //ÕºœÒ—πÀı±»¬ 

	imwrite("lena.jpg", src,compression_params);

	dst = imread("lena.jpg", 1);

	imshow("srcImage", src);
	imshow("dstImage", dst);

	waitKey(0);
	return 0;
}
*/