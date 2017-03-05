//
//  InPaint.hpp
//  PhotoRepair
//
//  Created by Honze on 2017/3/2.
//  Copyright © 2017年 Tsinghua. All rights reserved.
//

#ifndef InPaint_hpp
#define InPaint_hpp
#include "algorithm.h"

class Inpaint: public Algorithm
{
public:
    Inpaint(const cv::Mat& img): Algorithm(img){}
    void work();
};

#endif /* InPaint_hpp */
