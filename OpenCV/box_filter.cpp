#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    cv::Mat src = cv::imread("input.jpg", cv::IMREAD_GRAYSCALE);

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

    return 0;
}