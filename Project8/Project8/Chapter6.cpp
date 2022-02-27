#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int hmin = 0, smin = 110, vmin = 153, hmax = 19, smax = 240, vmax = 255;

/////////////////  Color detection  //////////////////////

void main() {
   // string path = "Resources/lambo.png";
    VideoCapture cap(0);  //0 if only 1 camera attached
    Mat img;// = imread(path);
    Mat imghsv,mask;
   

    namedWindow("Trackbars", (640, 200));
    createTrackbar("Hue Min", "Trackbars", &hmin, 179);
    createTrackbar("Hue Max", "Trackbars", &hmax, 179);
    createTrackbar("Sat Min", "Trackbars", &smin, 255);
    createTrackbar("Sat Max", "Trackbars", &smax, 255);
    createTrackbar("V Min", "Trackbars", &vmin, 255);
    createTrackbar("V Max", "Trackbars", &vmax, 255);

    while (true)
    {
        cap.read(img);

        cvtColor(img, imghsv, COLOR_BGR2HSV);
        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);


        inRange(imghsv, lower, upper, mask);


        imshow("Image", img);
        imshow("Image_HSV", imghsv);
        imshow("Mask", mask);
        waitKey(1);

    }
   
}
