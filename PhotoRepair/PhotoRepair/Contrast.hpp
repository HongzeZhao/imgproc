//
//  Contrast.hpp
//  PhotoRepair
//
//  Created by Honze on 2017/3/4.
//  Copyright © 2017年 Tsinghua. All rights reserved.
//

#ifndef Contrast_hpp
#define Contrast_hpp
#include "algorithm.h"

class Contrast : public Algorithm{
    int alpha;
    int beta;
public:
    Contrast(const cv::Mat& img);
    void work();
    void onslider();
};

#endif /* Contrast_hpp */
