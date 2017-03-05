//
//  Buffing.cpp
//  PhotoRepair
//
//  Created by Honze on 2017/3/5.
//  Copyright © 2017年 Tsinghua. All rights reserved.
//

#include "Buffing.hpp"
using namespace cv;

Buffing::Buffing(const cv::Mat& img): Algorithm(img) {
    winname = "bilateralFilter";
}

void Buffing::work()
{
    imshow(winname, input);
    createTrackbar("d", winname, &d, 50, track_callback, this);
    createTrackbar("sigmaColor", winname, &sigmaColor, 100, track_callback, this);
    createTrackbar("sigmaSpace", winname, &sigmaSpace, 100, track_callback, this);
}

void Buffing::ontrack()
{
    bilateralFilter(input, output, d + 1, sigmaColor, sigmaSpace);
    imshow(winname, output);
}