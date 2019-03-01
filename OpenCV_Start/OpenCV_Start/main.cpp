//
//  main.cpp
//  OpenCV_Start
//
//  Created by zibin on 2/28/19.
//  Copyright © 2019 zibin. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    if (argc !=2){
        cout<<"usage : run <image file>\n"<<endl;
        cout<<"argc: "<<argc<<endl;
        return -1;
    }
    
    cout<<"reading "<<argv[1]<<endl;
    
    Mat img;
    img = imread(argv[1]);
    
    if(!img.data){
        cout<<"Error: could not open or find the image with name : "<<argv[1]<<endl;
        return -1;
    }
    imshow(argv[1],img);
    waitKey();
    
    return 0;
}
