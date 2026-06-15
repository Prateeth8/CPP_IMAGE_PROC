#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img = cv::imread("bird-8788491_1280.jpg", cv::IMREAD_GRAYSCALE);
    if (img.empty()) return -1;

    cv::Mat gaussian_denoised, median_denoised;


    cv::GaussianBlur(img, gaussian_denoised, cv::Size(5, 5), 0);
    cv::medianBlur(img, median_denoised, 5);

    cv::imwrite("gaussian_output.jpg", gaussian_denoised);
    cv::imwrite("median_output.jpg", median_denoised);

    return 0;
}