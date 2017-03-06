//
//  MouseROI.hpp
//  PhotoRepair
//
//  Created by Honze on 2017/3/6.
//  Copyright © 2017年 Tsinghua. All rights reserved.
//

#ifndef MouseROI_hpp
#define MouseROI_hpp

#include "algorithm.h"

class MouseROI : public Algorithm
{
    cv::Point startpos;
    cv::Point endpos;
    bool is_drawing;
    int blur_size;
public:
    MouseROI(const cv::Mat& img);
    void work();
    void ontrack();
    void update();
    void on_mouse_move(int x, int y);
    void on_lbutton_down(int x, int y);
    void on_lbutton_up(int x, int y);
};

#endif /* MouseROI_hpp */
