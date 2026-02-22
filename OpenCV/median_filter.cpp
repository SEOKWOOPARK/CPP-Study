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
    cv::Mat destination;
    cv::medianBlur(src, destination, k_size);

    cv::imshow("Original", src);
    cv::imshow("Median Blur", destination);
    cv::waitKey();

    return 0;
}