#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main() {
    cv::Mat src = cv::imread("input.jpg", cv::IMREAD_GRAYSCALE);

    if (src.empty()) {
        cout << "Could not open .jpg" << endl;
        return -1;
    }

    int k_size = 5;
    if (k_size % 2 == 0) k_size += 1;
    if (k_size < 1) k_size = 1;

    cv::Mat lap16;
    cv::Laplacian(src, lap16, CV_16S, k_size, 1.0, 0.0, cv::BORDER_DEFAULT);

    cv::Mat lap8;
    cv::convertScaleAbs(lap16, lap8);

    cv::imshow("src", src);
    cv::imshow("laplacian", lap8);

    cv::imwrite("laplacian.png", lap8);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}