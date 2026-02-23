#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Reference: https://docs.opencv.org/3.4/d4/d86/group__imgproc__filter.html#ga564869aa33e58769b4469101aac458f9
// Reference for vector.begin() https://cplusplus.com/reference/vector/vector/begin/

int main() {
    // cv::Mat stores image data as a flat memory block internally, not a 2D array.
    //
    cv::Mat src = cv::imread("input.jpg", cv::IMREAD_GRAYSCALE);

    if (src.empty()) {
        cout << "Could not open .jpg" << endl;
        return -1;
    }

    int k_size = 5; // kernel size

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
    window.reserve(k_size * k_size); // Pre-allocating the capacity of the vector)

    // Loops over every pixel, skipping borders -> y and x start at radius
    for (int y = radius; y < src.rows - radius; y++) {
        uchar* out = destination2.ptr<uchar>(y);

        for (int x = radius; x < src.cols - radius; x++) {
            window.clear();

            // Collecting neighborhood pixels
            for (int dy = -radius; dy <= radius; dy++) { // dy = -1, 0, 1   (rows:   above, center, below)
                // When 'src.at<uchar>(y, x)' is used, OpenCV calculates the position every time -> Too slow
                const uchar* row = src.ptr<uchar>(y + dy);

                for (int dx = -radius; dx <= radius; dx++) { // dx = -1, 0, 1   (cols:   left, center, right)
                    window.push_back(row[x + dx]);
                }
            }

            // window.begin() returns an iterator(vector<uchar>::iterator) to the start of the vector
            // window.size() returns just integer
            vector<uchar>::iterator middle = window.begin() + window.size() / 2;
            // nth_element partially sorts the vector so that the middle position has the correct median value.
            nth_element(window.begin(), middle, window.end());
            // middle is an iterator (like a pointer) pointing to the median element inside window vector.
            // To get the actual value it points to, dereferencing it with *.
            out[x] = *middle;
        }
    }

    cv::imshow("Original", src);
    cv::imshow("Median Blur", destination2);
    cv::waitKey(0);

    return 0;
}