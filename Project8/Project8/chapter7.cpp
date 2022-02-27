#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//int hmin = 0, smin = 110, vmin = 153, hmax = 19, smax = 240, vmax = 255;



void getContours(Mat imgdil, Mat img)
    {
        vector<vector<Point>> contours;
        vector<Vec4i> hierarchy;


        findContours(imgdil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_NONE);
        //drawContours(img, contours, -1, Scalar(255, 0, 255), 2);

        //to remove image noise

        for (int i = 0; i < contours.size(); i++)
        {
            int area = contourArea(contours[i]);
           // cout << area << endl;

            vector<vector<Point>>conPoly(contours.size());
            vector<Rect> boundRect(contours.size());
            string objectType;
            if (area > 5000&&  area <50000)
            {
                float p = arcLength(contours[i], true);

                approxPolyDP(contours[i], conPoly[i], 0.02 * p, true);

                drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);

                boundRect[i] = boundingRect(conPoly[i]);
                rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 0, 0), 2);

                int objCor = (int)conPoly[i].size();

                switch (objCor)
                {
                case 3: objectType = "Triangle"; break;
                case 4:
                { float aRatio = (float)boundRect[i].width / (float)boundRect[i].height;

                if ((aRatio > 0.95) && (aRatio < 1.05))
                {
                    objectType = "Square";
                }
                else
                {
                    objectType = "Rectangle";
                }
                }   break;
                case 5: objectType = "Pentagon"; break;
                case 6: objectType = "Hexagon";  break;
                case 7: objectType = "Septagon"; break;
                case 8: objectType = "Octagon"; break;
                default:objectType = "Circle"; break;
                }

                putText(img, objectType, { boundRect[i].x,boundRect[i].y - 5 }, FONT_HERSHEY_PLAIN, 1.5, Scalar(169, 69, 169), 2);


            }
        }
    
}
int hmin = 0, smin = 150, vmin = 10, hmax = 11, smax = 255, vmax = 255;
int s = 1,a=5,b=1,kmin=50,kmax=150;
void main() {
   // string path = "Resources/test002.jpg";
   // 0 if only 1 camera attached
        VideoCapture cap(0); 
        Mat img;
    Mat imgresize, imgcrop;
  /*namedWindow("Trackbars", (640, 200));
    createTrackbar("Hue Min", "Trackbars", &hmin, 179);
    createTrackbar("Hue Max", "Trackbars", &hmax, 179);
    createTrackbar("Sat Min bl", "Trackbars", &smin, 255);
    createTrackbar("Sat Max a", "Trackbars", &smax, 61);
    createTrackbar("V Min a", "Trackbars", &vmin, 60);
    createTrackbar("V Max b", "Trackbars", &vmax, 60);
    createTrackbar(" a", "Trackbars", &a, 60);
    createTrackbar(" b", "Trackbars", &b, 60);
    createTrackbar(" kmin", "Trackbars", &kmin, 255);
    createTrackbar(" kmax", "Trackbars", &kmax, 255);
    */
    while (1) {
        cap.read(img);
       // resize(img, imgresize, Size(), 1, 1);

        Mat imggray, imgblur, imgCanny, imgdia, imgerode,mask,imghsv;
        /// <summary>
        /// making image shapes more detectable 
        /// </summary>
       // while (1) {
          //  cap.read(img);
       /* cvtColor(img, imghsv, COLOR_BGR2HSV);
        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);


        inRange(imghsv, lower, upper, mask);

        */
        /*
        cvtColor(img, imghsv, COLOR_BGR2HSV);
        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);


        inRange(imghsv, lower, upper, mask);
        */
       cvtColor(img, imggray, COLOR_BGR2GRAY);
       // s = 2 * s - 1;
        GaussianBlur(imggray, imgblur, Size(7,7), 5, 0);

        Canny(imgblur, imgCanny, kmin, kmax);


        Mat kernel = getStructuringElement(MORPH_RECT, Size(4, 4));
        dilate(imgCanny, imgdia, kernel);

        /// <summary>
        /// 
        /// </summary>

        getContours(imgdia, img);
        //imshow("canny", imgCanny);
       // imshow("blur", imgblur);
        imshow("IMAGE", img);
      //  imshow("DIA", imgdia);

        waitKey(1);
    }
}
