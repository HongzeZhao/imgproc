//
//  algorithm.h
//  PhotoRepair
//
//  Created by Honze on 2017/3/2.
//  Copyright © 2017年 Tsinghua. All rights reserved.
//

#ifndef algorithm_h
#define algorithm_h

#include <opencv2/opencv.hpp>
#include <functional>

class Algorithm {
public:
    Algorithm(const cv::Mat& img): input(img){}
    const cv::Mat& input;
    cv::Mat output;
    cv::String winname;
    virtual void work() = 0;
    virtual void ontrack() {}
    virtual ~Algorithm(){}
};

template<typename T>
Algorithm* create(const cv::Mat& img){
    return new T(img);
}

template<typename T>
void destroy(T *p){
    delete p;
}

template<typename T>
void run(const cv::Mat& img){
    auto p = create<T>(img);
    p->work();
    cv::waitKey();
    destroy(p);
}

static void track_callback(int,void* o){
    ((Algorithm*)o)->ontrack();
};

#endif /* algorithm_h */
