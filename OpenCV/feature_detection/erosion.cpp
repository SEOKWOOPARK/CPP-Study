#include <iostream>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;

int main() {

    Mat src = imread("input.jpg", IMREAD_GRAYSCALE);

    if (src.empty()) {
        cout << "Could not open .jpg" << endl;
        return -1;
    }

    Mat binary;
    threshold(src, binary, 127, 255, THRESH_BINARY);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));

    Mat destination;
    erode(binary, destination, kernel);

    imshow("src", src);
    imshow("binary", binary);
    imshow("erosion", destination);
    imwrite("erosion.png", destination);

    waitKey(0);
    destroyAllWindows();

    return 0;
}