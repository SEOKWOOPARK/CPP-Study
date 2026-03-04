#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat manualLaplacian(const Mat& src) {
    int kernel_size= 5;
    int padding = kernel_size / 2;

    Mat kernel = (cv::Mat_<float>(5, 5) <<
        0, 0, 1, 0, 0,
        0, 1, 1, 1, 0,
        1, 1, -8, 1, 1,
        0, 1, 1, 1, 0,
        0, 0, 1, 0, 0
    );

    Mat padded;
    copyMakeBorder(src, padded, padding, padding, padding, padding, BORDER_DEFAULT);

    Mat lap16 = Mat::zeros(src.rows, src.cols, CV_16S);

    for (int y = 0; y < src.rows; y++) {
        for (int x = 0; x < src.cols; x++) {
            float sum = 0.0f;
            for (int ky = 0; ky < kernel_size; ky++) {
                for (int kx = 0; kx < kernel_size; kx++) {
                    float pixel = padded.at<uchar>(y + ky, x + kx);
                    float weight = kernel.at<float>(ky, kx);
                    sum += pixel * weight;
                }
            }
            // short: -32768 ~ 32767
            // uchar: 0 ~ 255
            lap16.at<short>(y, x) = saturate_cast<short>(sum);
        }
    }

    return lap16;
}

int main() {
    Mat src = imread("input.jpg", IMREAD_GRAYSCALE);

    if (src.empty()) {
        cout << "Could not open .jpg" << endl;
        return -1;
    }

    int k_size = 5;

    Mat lap16;
    Laplacian(src, lap16, CV_16S, k_size, 1.0, 0.0, BORDER_DEFAULT);

    Mat lap8;
    convertScaleAbs(lap16, lap8);

    imshow("src", src);
    imshow("laplacian", lap8);
    imwrite("laplacian.png", lap8);

    waitKey(0);
    destroyAllWindows();

    // ------------------------------------------------------------

    Mat lap16_manual = manualLaplacian(src);
    Mat lap8_manual;
    convertScaleAbs(lap16_manual, lap8_manual);

    imshow("src", src);
    imshow("laplacian", lap8_manual);
    imwrite("laplacian.png", lap8_manual);
    waitKey(0);
    destroyAllWindows();

    return 0;
}