//
//  main.cpp
//  PhotoRepair
//
//  Created by Honze on 2016/12/27.
//  Copyright © 2016年 Tsinghua. All rights reserved.
//

#include <vector>
#include <string>
#include "InPaint.hpp"
#include "Contrast.hpp"
#include "Buffing.hpp"
#include "FaceDetection.hpp"

int main(int argc, const char * argv[]) {
    auto img = cv::imread("/users/honze/downloads/hy.jpg");
    
    //run<Inpaint>(img);
    //run<Contrast>(img);
    //run<Buffing>(img);
    run<FaceDetection>(img);

    return 0;
}
