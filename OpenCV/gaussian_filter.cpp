#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>

using namespace std;
using namespace cv;

Mat createGaussianKernel(int kernel_size, double sigma) {
    Mat kernel(kernel_size, kernel_size, CV_64F);
    int center = kernel_size / 2;
    double sum = 0.0;

    for (int row = 0; row < kernel_size; row++) {
        for (int col = 0; col < kernel_size; col++) {
            int x = col - center;
            int y = row - center;

            double value = exp(-(x * x + y * y) / (2.0 * sigma * sigma));
            kernel.at<double>(row, col) = value;
            sum += value;
        }
    }

    kernel /= sum;

    return kernel;
}

int main() {
    Mat src = imread("input.jpg", cv::IMREAD_GRAYSCALE);

    if (src.empty()) {
        cout << "Could not open or find the image" << endl;
        return - 1;
    }

    int kernel_size = 5;

    Mat destination1;
    GaussianBlur(src, destination1, Size(kernel_size, kernel_size), 0);

    // imshow("Original", src);
    // imshow("Gaussian Blur", destination1);
    // waitKey(0);

    // ------------------------------------------------------------------------------------------------

    double sigma = 1.1;
    Mat kernel = createGaussianKernel(kernel_size, sigma);

    cout << fixed << setprecision(4);

    for (int row = 0; row < kernel_size; row++) {
        for (int col = 0; col < kernel_size; col++) {
            cout << kernel.at<double>(row, col) << " ";
        }
        cout << endl;
    }

    return 0;
}
