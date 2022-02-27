
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////  Images  //////////////////////
//Video
//void main() {
//    string path = "Resources/SampleVideo_1280x720_2mb.mp4";
//    VideoCapture cap(path);
//    Mat img;
//    while (true) {
//       
//        cap.read(img);
//        imshow("Image", img);
//        waitKey(20);
//    }
//}
// WEBCAM
int hmin = 50, hmax = 150;
int b = 50, l = 50;
void main() {
	string path = "Resources/img-test1.jpeg";
	  //  VideoCapture cap(0);  //0 if only 1 camera attached
	    Mat img=imread(path);
		Mat imgres;
		
		namedWindow("Trackbars", (640, 200));
		createTrackbar(" Min", "Trackbars", &hmin, 179);
		createTrackbar(" Max", "Trackbars", &hmax, 179);
		createTrackbar(" b", "Trackbars", &b, 100);
		createTrackbar(" l", "Trackbars", &l, 100);
	    while (true) {
			resize(img, imgres, Size(), 1, 0.8);
	        //cap.read(img);
			Mat imgCanny;
			Canny(imgres, imgCanny, hmin, hmax);
	        imshow("Image", imgCanny);
	        waitKey(1);
	    }
	}