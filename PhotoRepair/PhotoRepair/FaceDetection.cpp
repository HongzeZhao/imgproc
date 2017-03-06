//
//  FaceDetection.cpp
//  PhotoRepair
//
//  Created by Honze on 2017/3/5.
//  Copyright © 2017年 Tsinghua. All rights reserved.
//

#include "FaceDetection.hpp"
#include <iostream>

using namespace cv;
using namespace std;

FaceDetection::FaceDetection(const cv::Mat &img): Algorithm(img)
{
    winname = "FaceDetection";
}

void FaceDetection::work()
{
    // need settings to copy this xml file to dst folder
    String face_cascade_name = "haarcascade_frontalface_alt.xml";
    CascadeClassifier face_cascade;
    
    if (!face_cascade.load( face_cascade_name ))
        throw "cannot load haarcascade_frontalface_alt.xml";
    
    std::vector<Rect> faces;
    Mat frame_gray;
    
    cvtColor( input, frame_gray, CV_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );
    
    face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );
    
    input.copyTo(output);
    
    for( size_t i = 0; i < faces.size(); i++ )
    {
        rectangle(output, faces[i], Scalar( 50, 255, 50 ));
    }
    
    imshow(winname, output);
}