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
    Mat imggray,imgblur,imgCanny,imgdia,imgerode;

    cvtColor(img, imggray, COLOR_BGR2GRAY);
    GaussianBlur(img, imgblur, Size(7, 7), 5, 0);

    Canny(imgblur, imgCanny, 25, 75);

    Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
        dilate(imgCanny, imgdia,kernel);
    imshow("IMAGE_2", img);
    imshow("IMAGE_2_gray", imgblur);
    imshow("IMAGE_2_canny", imgCanny);
    imshow("IMGDIA", imgdia);
    erode(imgdia, imgerode, kernel);
    imshow("IMGERODE", imgerode);
    waitKey(0);

}
    
