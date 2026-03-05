#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat manualBoxFilter(const Mat& src) {
    int kernel_size = 5;
    int padding = kernel_size / 2;
    float weight = 1.0f / float(kernel_size * kernel_size);

    Mat padded;
    copyMakeBorder(src, padded, padding, padding, padding, padding, BORDER_DEFAULT);
    Mat destination = Mat::zeros(src.rows, src.cols, CV_8U);

    for (int y = 0; y < src.rows; y++) {
        for (int x = 0; x < src.cols; x++) {
            float sum = 0.0f;

            for (int ky = 0; ky < kernel_size; ky++) {
                for (int kx = 0; kx < kernel_size; kx++) {
                    sum += padded.at<uchar>(y + ky, x + kx) * weight;
                }
            }

            destination.at<uchar>(y, x) = saturate_cast<uchar>(sum);
        }
    }

    return destination;
}

int main() {
    Mat src = imread("input.jpg", IMREAD_GRAYSCALE);

    if (src.empty()) {
        cout << "Could not open .jpg" << endl;
        return -1;
    }

    Mat destination;
    boxFilter(src, destination, -1, Size(5, 5));

    imshow("src", src);
    imshow("box filter", destination);
    imwrite("box_filter.jpg", destination);

    waitKey(0);
    destroyAllWindows();

    // ----------------------------------------------------------------

    Mat manual_destination = manualBoxFilter(src);

    imshow("src", src);
    imshow("manual box filter", manual_destination);
    imwrite("manual box filter.png", manual_destination);
    waitKey(0);
    destroyAllWindows();

    return 0;
}