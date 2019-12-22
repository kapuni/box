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

	Mat ele = getStructuringElement(MORPH_RECT, Size(5, 5)); //getStructuringElement����ֵ�����ں˾���
	//erode(src, dst, ele);  //��ʴ
	//dilate(src, dst, ele);   //����
	
	erode(src, tmp, ele);    //������  ���ȸ�ʴ������
	dilate(tmp, dst, ele);
	
	imshow("secImage", src);
	imshow("dstImage", dst);

	waitKey(0);

	return 0;
}