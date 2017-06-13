
#pragma warning (disable : 4996)
#include <iostream>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <opencv2\objdetect.hpp>
#include <opencv2\core\ocl.hpp>

#include <vector>


using namespace std;
using namespace cv;
using namespace cv::ocl;


int main()
{
	VideoCapture cap(0);
	CascadeClassifier fd("haarcascade_frontalface_default.xml");

	Mat frame; 
	UMat gray;

	//vector faces;

	for (;;)
	{
		cap >> frame;

		int width = frame.cols;
		int height = frame.rows;

		cvtColor(frame, gray, COLOR_BGR2GRAY);
		resize(gray, gray, Size(width * 0.5, height * 0.5));
		equalizeHist(gray, gray);

		vector<Rect> rects;

		//It takes lots of times.
		fd.detectMultiScale(gray, rects, 1.1, 2, 0);

		for (Rect object : rects) {
			Point center(object.x * + object.width / 2, object.y + object.height / 2);
			object.x *= 2;
			object.y *= 2;
			object.width *= 2;
			object.height *= 2;

			rectangle(frame, object, Scalar(255, 0, 255), 3);
		}

		imshow("hello", frame);

		if (waitKey(40) >= 0) {
			imwrite("captured.jpg", frame);
			break;
		}
	}


	return 0;

}
