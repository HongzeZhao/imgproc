//
//  Contrast.cpp
//  PhotoRepair
//
//  Created by Honze on 2017/3/4.
//  Copyright © 2017年 Tsinghua. All rights reserved.
//

#include "Contrast.hpp"
#include <functional>
#include <string>

using namespace cv;
using namespace std;

Contrast::Contrast(const cv::Mat& img):Algorithm(img), alpha(10), beta(256) {
    winname = "g(x)=alpha*f(x)+beta";
}

void Contrast::work()
{
    imshow(winname, input);
    auto slider_callback = [](int,void* ref){
        ((Contrast*)ref)->onslider();
    };
    createTrackbar("alpha", winname, &this->alpha, 100, slider_callback, this);
    createTrackbar("beta", winname, &this->beta, 512, slider_callback, this);
    output = Mat::zeros(input.rows, input.cols, input.type());
}

void Contrast::onslider()
{
    double a = this->alpha / 10.0;
    double b = this->beta - 256.0;
    input.convertTo(output, -1, a, b);
    
    rectangle(output, Rect(10, 0, 500, 30), Scalar(0, 0, 0, 0.3), CV_FILLED);
    auto text = format("Alpha: %.1f, Belta: %.1f", a, b);
    auto color = Scalar(255, 255, 255);
    putText(output, text, Point(10, 20), FONT_HERSHEY_PLAIN, 1, color);
    
    imshow(winname, output);
}