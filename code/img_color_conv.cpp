#include<opencv2/opencv.hpp>
#include<iostream>

int main()
{
    std::string img_path = "bird-8788491_1280.jpg";
    cv::Mat image = cv::imread(img_path);

    if(image.empty())
    {
        std::cerr<<"Error reading image from path:"<<img_path<<std::endl;
        return -1;
    }

    //cv::Mat gray_img;
    //cv::cvtColor(image, gray_img, cv::COLOR_BGR2GRAY);

    cv::Mat lab_img;
    cv::cvtColor(image, lab_img, cv::COLOR_BGR2Lab);

    bool success = cv::imwrite("lab_out.jpg",lab_img);

    if (success) {
        std::cout << "Image successfully read, converted to LAB, and saved as lab_out.jpg!" << std::endl;
    } else {
        std::cerr << "Failed to write the LAB image." << std::endl;
    }
    return 0;
}