#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

int main(int, char **argv)
{
	Mat src;
	Mat tmp;
	Mat dst;

	src = imread("F:/workspace/box/opencv3/image/cat3.jpg", 1);

	if (src.empty())
	{
		return -1;
	}

	Mat ele = getStructuringElement(MORPH_RECT, Size(5, 5)); //getStructuringElement返回值定义内核矩阵
	//erode(src, dst, ele);  //腐蚀
	//dilate(src, dst, ele);   //膨胀
	
	erode(src, tmp, ele);    //开运算  ，先腐蚀再膨胀
	dilate(tmp, dst, ele);
	
	imshow("secImage", src);
	imshow("dstImage", dst);

	waitKey(0);

	return 0;
}