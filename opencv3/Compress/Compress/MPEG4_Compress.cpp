#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

int main(int, char**argv)
{
	VideoCapture capture(0);
	VideoWriter write("VideoTest.avi", CV_FOURCC('D', 'T', 'V', 'X'), 25.0, Size(640, 480));
	Mat frame;
	while (capture.isOpened())
	{
		capture >> frame;
		write << frame;
		imshow("video", frame);
		if (cvWaitKey(20) == 27)
		{
			break;
		}
	}

	return 0;
}