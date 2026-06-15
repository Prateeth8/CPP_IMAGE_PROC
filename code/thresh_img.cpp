#include<opencv2/opencv.hpp>
#include<iostream>

int main()
{
    std:: string img_path = "bird-8788491_1280.jpg";
    cv::Mat image = cv::imread(img_path);

    if(image.empty())
    {
        std::cerr<<"Error reading image from path:"<<img_path<<std::endl;
        return -1;
    }

    cv::Mat gray_img;
    cv::cvtColor(image,gray_img,cv::COLOR_BGR2GRAY);

    cv::Mat thresh_img;
    cv::threshold(gray_img, thresh_img,180.0,255.0,cv::THRESH_BINARY);

    cv::Mat thresh_color_img;
    cv::cvtColor(thresh_img, thresh_color_img, cv::COLOR_GRAY2BGR);

    cv::Mat comb_color_img;
    cv::hconcat(image, thresh_color_img, comb_color_img);

    cv::Mat comb_gray_img;
    cv::hconcat(gray_img, thresh_img, comb_gray_img);

    bool success = cv::imwrite("thresh_out_gray_2.jpg",comb_gray_img);

    if (success) {
        std::cout << "Image successfully read, thresholded, and saved as thresh_out.jpg!" << std::endl;
    } else {
        std::cerr << "Failed to write the thresholded image." << std::endl;
    }
    return 0;
}