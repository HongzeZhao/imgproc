//
//  Buffing.hpp
//  PhotoRepair
//
//  Created by Honze on 2017/3/5.
//  Copyright © 2017年 Tsinghua. All rights reserved.
//

#ifndef Buffing_hpp
#define Buffing_hpp

#include "algorithm.h"

class Buffing: public Algorithm
{
    int d;
    int sigmaColor;
    int sigmaSpace;
public:
    Buffing(const cv::Mat& img);
    void work();
    void ontrack();
};

#endif /* Buffing_hpp */
