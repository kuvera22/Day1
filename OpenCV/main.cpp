/*#include "opencv2\opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(int, char**)
{
	VideoCapture cap("C:\\Users\\Xiaomi\\Downloads\\Penalty.MP4");
	if (cap.isOpened() == false)
	{
		cout << "Cannot open video" << endl;
		cin.get();
		return -1;
	}

	double fps = cap.get(CAP_PROP_FPS);
	cout << "Frames per seconds : " << fps << endl;

	String window_name = "First Video";
	namedWindow(window_name, WINDOW_NORMAL);
	while (true)
	{
		Mat frame;
		bool bSuccess = cap.read(frame);

		if (bSuccess == false) {
			cout << "Found the end of the video" << endl;
			break;
		}
		imshow(window_name, frame);
		if (waitKey(10) == 27) 
		{
			cout << "ESC pressed. Closing..." << endl;
			break;
		}

	}
	return 0;
}*/

#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace cv;

int main(int argc, char* argv[]) {
	VideoCapture cap("C:\\Users\\Xiaomi\\Downloads\\Penalty.MP4"); // open the video file for reading
	if (!cap.isOpened()) return -1;
	//cap.set(CV_CAP_PROP_POS_MSEC, 300); //start the video at 300ms
	double fps = cap.get(CV_CAP_PROP_FPS); //get the frames per seconds of the video
	std::cout << "Frame per seconds : " << fps << std::endl;
	namedWindow("MyVideo", CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"
	while (1) {
		Mat frame;
		bool bSuccess = cap.read(frame); // read a new frame from video
		if (!bSuccess) {
			std::cout << "Cannot read the frame from video file" << std::endl;
			break;
		}
		imshow("MyVideo", frame); //show the frame in "MyVideo" window
		if (waitKey(30) == 27) {
			break;
		}
	}
}