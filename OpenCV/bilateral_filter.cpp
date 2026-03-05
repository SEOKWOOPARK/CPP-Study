#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {

    Mat src = imread("input.jpg", IMREAD_GRAYSCALE);

    if (src.empty()) {
        cout << "Could not open .jpg" << endl;
        return -1;
    }

    Mat destination;
    bilateralFilter(src, destination, 9, 75, 75);

    imshow("src", src);
    imshow("bilateral filter", destination);
    imwrite("bilateral_filter.png", destination);

    waitKey(0);
    destroyAllWindows();
    return 0;
}