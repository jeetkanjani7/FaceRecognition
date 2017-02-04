#include<opencv2\highgui\highgui.hpp>
#include<opencv2\core\core.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\objdetect\objdetect.hpp>
#include<stdio.h>
#include<iostream>


using namespace std;
using namespace cv;


void main()
{

	Mat original, grayscale, blured;
	Mat dst;
	String class_address = "C:/OpenCV-3.1.0/opencv/sources/samples/winrt/FaceDetection/FaceDetection/Assets/haarcascade_frontalface_alt.xml";
	int const lower_thresh = 100;
	int thresh_ratio = 3, kernel_thresh = 2;
	int j=0;
	string barack_filename;
	string image_name;
	while (j !=2498 )
	{
		j++;
		
		image_name = "D:/opencv_res/dataset/BarackObama/0/images/" + to_string(j) + ".jpg";
		original = imread(image_name);
		if (original.empty())
		{
			cout << "Image not found";
			continue;
		}

		//------------------------------------------------------------------------------------------------------
			//CASCADE CLASSIFIER OBJECTS
		float scale_factor = 1.1;
		int min_neighbours = 2;
		vector<Rect> oboi;
		Rect roi_a;
		int aoi_a = 0;
		Mat feature;
		string filename;

		//------------------------------------------------------------------------------------------------------

		
		cvtColor(original, grayscale, CV_BGR2GRAY);

		CascadeClassifier classifier = CascadeClassifier(class_address);
		if (!classifier.load(class_address))
		{
			cout << "cannot load classifier";
			cvDestroyAllWindows();
			exit(0);
		}
		else
		{
			cout << "yes we can";
		}

		classifier.detectMultiScale(original, oboi, min_neighbours, scale_factor, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));
		cout << "the no of objects I found: " << oboi.size();
		for (int i = 0; i < oboi.size(); i++)
		{

			roi_a.x = oboi[i].x;
			roi_a.y = oboi[i].y;
			roi_a.width = oboi[i].width;
			roi_a.height = oboi[i].height;
			line(original, Point(roi_a.x, roi_a.y), Point(roi_a.x + roi_a.width, roi_a.y), Scalar(94.0, 206.0, 165.0, 0.0), 2, 8, 0);
			line(original, Point(roi_a.x, roi_a.y + roi_a.height), Point(roi_a.x + roi_a.width, roi_a.y + roi_a.height), Scalar(94.0, 206.0, 165.0, 0.0), 2, 8, 0);
			line(original, Point(roi_a.x, roi_a.y), Point(roi_a.x, roi_a.y + roi_a.height), Scalar(94.0, 206.0, 165.0, 0.0), 2, 8, 0);
			line(original, Point(roi_a.x + roi_a.width, roi_a.y), Point(roi_a.x + roi_a.width, roi_a.y + roi_a.height), Scalar(94.0, 206.0, 165.0, 0.0), 2, 8, 0);
			feature = original(roi_a);
			stringstream filestream;
			filestream << j << ".png";
			filename = "D:/opencv_res/dataset/BarackObama/0/images/cropped/" + filestream.str();
			imwrite(filename, feature);
		}
		

	}

	
	waitKey(0);
	

}