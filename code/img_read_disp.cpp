#include<opencv2/opencv.hpp>
#include<iostream>

int main()
{
    std::string img_path = "bird-8788491_1280.jpg";
    cv::Mat img = cv::imread(img_path);

    if(img.empty())
    {
        std::cerr<<"Error reading image from path:"<<img_path<<std::endl;
        return -1;
    }

    bool success = cv::imwrite("success_output.jpg", img);
    
    if (success) {
        std::cout << "Image successfully read and saved as success_output.jpg!" << std::endl;
    } else {
        std::cerr << "Failed to write the image." << std::endl;
    }
    return 0;

}