#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Read the image in color for this one
    cv::Mat img = cv::imread("bird-8788491_1280.jpg", cv::IMREAD_COLOR);
    if (img.empty()) {
        std::cerr << "Error reading image." << std::endl;
        return -1;
    }

    cv::Mat segmented_img = img.clone();
    cv::Point seedPoint(100, 100); 

    cv::Scalar newVal(0, 255, 0); 

    cv::Scalar lowerDiff(20, 20, 20); 
    cv::Scalar upperDiff(40, 40, 40); 

    cv::floodFill(segmented_img, seedPoint, newVal, nullptr, lowerDiff, upperDiff);

    if (cv::imwrite("region_grown.jpg", segmented_img)) {
        std::cout << "Success! Saved Region Grown image to region_grown.jpg" << std::endl;
    }

    return 0;
}