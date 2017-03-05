//
//  InPaint.cpp
//  PhotoRepair
//
//  Created by Honze on 2017/3/2.
//  Copyright © 2017年 Tsinghua. All rights reserved.
//

#include "InPaint.hpp"

using namespace cv;

void Inpaint::work(){
    
    // get the hint image
    //Mat img(srcImg, Rect(205, 637, 340, 340));
    
    auto img = input;
    Mat gray;
    cvtColor(img, gray, CV_BGR2GRAY);
    Mat mask;
    threshold(gray, mask, 50, 255, THRESH_BINARY_INV);
    auto structElement = getStructuringElement(MORPH_ELLIPSE, cvSize(9, 9));
    morphologyEx(mask, mask, MORPH_DILATE, structElement);
    
    inpaint(img, mask, output, 4, INPAINT_TELEA);
    
    imshow("src", img);
    imshow("gray", gray);
    imshow("mask", mask);
    imshow("output", output);
}
