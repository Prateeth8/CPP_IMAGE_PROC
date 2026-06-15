#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img = cv::imread("bird-8788491_1280.jpg", cv::IMREAD_GRAYSCALE);
    if (img.empty()) return -1;

    cv::Mat laplacian_edges, abs_laplacian;

    cv::Laplacian(img, laplacian_edges, CV_16S, 3);

    cv::convertScaleAbs(laplacian_edges, abs_laplacian);

    cv::imwrite("edges_output.jpg", abs_laplacian);

    return 0;
}