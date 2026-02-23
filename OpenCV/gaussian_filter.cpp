#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    Mat src = imread("input.jpg", cv::IMREAD_GRAYSCALE);

    if (src.empty()) {
        cout << "Could not open or find the image" << endl;
        return - 1;
    }

    int kernel_size = 5;

    Mat destination1;
    GaussianBlur(src, destination1, Size(kernel_size, kernel_size), 0);

    imshow("Original", src);
    imshow("Gaussian Blur", destination1);
    waitKey(0);



    return 0;
}
