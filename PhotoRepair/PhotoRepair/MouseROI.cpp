//
//  MouseROI.cpp
//  PhotoRepair
//
//  Created by Honze on 2017/3/6.
//  Copyright © 2017年 Tsinghua. All rights reserved.
//

#include "MouseROI.hpp"

using namespace cv;

MouseROI::MouseROI(const cv::Mat& img): Algorithm(img), blur_size(10), is_drawing(false)
{
    winname = "MouseROI";
}

void MouseROI::work()
{
    imshow(winname, input);
    setMouseCallback(winname, [](int event, int x, int y, int flags, void* userdata){
        auto p = (MouseROI*)userdata;
        switch (event) {
            case CV_EVENT_MOUSEMOVE: p->on_mouse_move(x, y); break;
            case CV_EVENT_LBUTTONDOWN: p->on_lbutton_down(x, y); break;
            case CV_EVENT_LBUTTONUP: p->on_lbutton_up(x, y); break;
            default:
                break;
        }
    }, this);
    createTrackbar("Blur Size", winname, &this->blur_size, 50, track_callback, this);
}

void MouseROI::ontrack()
{
    input.copyTo(output);
    auto roi = output(Rect(startpos, endpos));
    blur(roi, roi, Size(blur_size + 1, blur_size + 1));
    imshow(winname, output);
}

void MouseROI::update()
{
    input.copyTo(output);
    rectangle(output, startpos, endpos, Scalar(0, 255, 255), 2);
    imshow(winname, output);
}

void MouseROI::on_mouse_move(int x, int y)
{
    if (!is_drawing)
        return;
    endpos = Point(x,y);
    update();
}

void MouseROI::on_lbutton_down(int x, int y)
{
    startpos = Point(x,y);
    is_drawing = true;
}

void MouseROI::on_lbutton_up(int x, int y)
{
    is_drawing = false;
    endpos = Point(x,y);
    if (startpos == endpos)
        return;
    ontrack();
}