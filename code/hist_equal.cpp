#include<opencv2/opencv.hpp>
#include<iostream>

int main()
{
    std::string img_path = "bird-8788491_1280.jpg";
    cv::Mat img = cv::imread(img_path, cv::IMREAD_COLOR);
    if (img.empty())
    {
        std::cerr << "Could not read the image: " << img_path << std::endl;
        return -1;   
    }
    cv::Mat img_gray;
    cv::cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);

    cv::Mat img_equalized;
    cv::equalizeHist(img_gray, img_equalized);

    cv::Mat comb_img;
    cv::hconcat(img_gray, img_equalized, comb_img);

    bool success = cv::imwrite("hist_equal.jpg", comb_img);
    if (!success)
    {
        std::cerr << "Could not write the image: hist_equal.jpg" << std::endl;
        return -1;
    }
    return 0;
}