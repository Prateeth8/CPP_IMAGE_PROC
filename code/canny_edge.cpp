#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::Mat img = cv::imread("bird-8788491_1280.jpg", cv::IMREAD_GRAYSCALE);
    if (img.empty()) {
        std::cerr << "Error reading image." << std::endl;
        return -1;
    }

    cv::Mat blurred_img;
    cv::GaussianBlur(img, blurred_img, cv::Size(5, 5), 0);

    cv::Mat edges;
    double lower_thresh = 50.0;
    double upper_thresh = 150.0;
    
    cv::Canny(blurred_img, edges, lower_thresh, upper_thresh);

    if (cv::imwrite("canny_edges.jpg", edges)) {
        std::cout << "Success! Saved Canny edges to canny_edges.jpg" << std::endl;
    }

    return 0;
}