#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Reference: https://docs.opencv.org/3.4/d4/d86/group__imgproc__filter.html#ga564869aa33e58769b4469101aac458f9

int main() {
    cv::Mat src = cv::imread("input.jpg", cv::IMREAD_GRAYSCALE);

    if (src.empty()) {
        cout << "Could not open .jpg" << endl;
        return -1;
    }

    int k_size = 5;

    // ------------------------------------------------------------

    // Built-in
    cv::Mat destination1;
    cv::medianBlur(src, destination1, k_size);

    cv::imshow("Original", src);
    cv::imshow("Median Blur", destination1);
    cv::waitKey();

    // ------------------------------------------------------------

    // Manual implementation
    int radius = k_size / 2;
    cv::Mat destination2 = cv::Mat::zeros(src.size(), CV_8UC1);
    vector<uchar> window;
    window.reserve(k_size * k_size);

    for (int y = radius; y < src.rows - radius; y++) {
        uchar* out = destination2.ptr<uchar>(y);

        for (int x = radius; x < src.cols - radius; x++) {
            window.clear();

            for (int dy = -radius; dy < radius; dy++) {
                const uchar* row = src.ptr<uchar>(y + dy);
                for (int dx = -radius; dx < radius; dx++) {
                    window.push_back(row[x + dx]);
                }
            }

            auto middle = window.begin() + window.size() / 2;
            nth_element(window.begin(), middle, window.end());
            out[x] = *middle;
        }
    }

    cv::imshow("Original", src);
    cv::imshow("Median Blur", destination2);
    cv::waitKey(0);

    return 0;
}