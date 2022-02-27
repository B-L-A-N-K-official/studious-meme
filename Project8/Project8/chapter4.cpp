#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


///////////////// shapes and text ////////////////////
void main() {

    Mat img(512, 512, CV_8UC3, Scalar(255, 0, 0));

    circle(img, Point(256, 256), 155, Scalar(100, 100, 100),FILLED);
    rectangle(img, Point(20, 20),Point( 100, 100),Scalar(0,0,0),FILLED);
    line(img, Point(130, 296), Point(382, 296), Scalar(123, 123, 123), 10);

    putText(img, "BRUHHHHHH", Point(137, 262), FONT_HERSHEY_COMPLEX_SMALL, 2, Scalar(169, 69, 169),2);
    imshow("IMAGE", img);
    waitKey(0);

}

