//
//  FaceDetection.hpp
//  PhotoRepair
//
//  Created by Honze on 2017/3/5.
//  Copyright © 2017年 Tsinghua. All rights reserved.
//

#ifndef FaceDetection_hpp
#define FaceDetection_hpp

#include "algorithm.h"

class FaceDetection: public Algorithm
{
public:
    FaceDetection(const cv::Mat &img);
    void work();
};

#endif /* FaceDetection_hpp */
