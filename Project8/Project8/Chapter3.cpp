#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////  Images  //////////////////////
//Video//
void main() {
    string path = "resources/download.jpg";
    Mat img = imread(path);
    Mat imgresize,imgcrop;

    resize(img, imgresize, Size(),5,5);
    imshow("IMAGE", imgresize);

    Rect roi(10, 10, 150, 150);
    imgcrop = imgresize(roi);

    imshow("CROP", imgcrop);
    waitKey(0);

}

