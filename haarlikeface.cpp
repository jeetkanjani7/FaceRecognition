#include<opencv2\highgui\highgui.hpp>
#include<opencv2\core\core.hpp>
#include<opencv2\imgproc\imgproc.hpp>

#include<stdio.h>
#include<iostream>


using namespace std;
using namespace cv;

void main()
{
	Mat original,grayscale,blured;
	Mat dst;
	int const lower_thresh=100;
	int thresh_ratio = 3,kernel_thresh=2;
	
	original = imread("D:/photos(new)/edit/IMG_20170123_215912_636.jpg");
	if (original.empty())
	{
		cout << "Image not found";
		exit(0);
	}
	namedWindow("detectface", CV_WINDOW_NORMAL);
	cvtColor(original, grayscale, CV_BGR2GRAY);
	
	blur(grayscale, blured, Size(3, 3));
	blured=Mat(blured.rows, blured.cols, CV_8UC1);
	
	
	//dst = Scalar::all(0);
	//original.copyTo(dst,blured);
	Canny(blured, blured, lower_thresh, lower_thresh*thresh_ratio, kernel_thresh);

	imshow("detectface", blured);
	waitKey(0);

}