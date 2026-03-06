#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    Mat src = imread("input2.png", IMREAD_GRAYSCALE);

    if (src.empty()) {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    Mat edges;
    Canny(src, edges, 30, 70);

    vector<Vec2f> lines;
    HoughLines(edges, lines, 1, CV_PI/180, 50);

    Mat destination;
    cvtColor(src, destination, COLOR_GRAY2BGR);

    for (auto& line : lines) {
        float rho = line[0];
        float theta = line[1];

        double cos_theta = cos(theta);
        double sin_theta = sin(theta);
        double x0 = cos_theta * rho;
        double y0 = sin_theta * rho;

        Point point1(x0 + 1000 * (-sin_theta), y0 + 1000 * (cos_theta));
        Point point2(x0 - 1000 * (-sin_theta), y0 - 1000 * (cos_theta));
        cv::line(destination, point1, point2, Scalar(255), 1);

        imshow("edges", edges);
        imshow("hough lines", destination);
        imwrite("hough_lines.png", destination);

        waitKey(0);
        destroyAllWindows();
        return 0;
    }
}