#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat manualBilateralFilter(const Mat& src, int d, double sigma_color, double sigma_space) {
    int padding = d / 2;

    Mat padded;
    copyMakeBorder(src, padded, padding, padding, padding, padding, BORDER_DEFAULT);
    Mat destination = Mat::zeros(src.rows, src.cols, CV_8U);

    for (int y = 0; y < src.rows; y++) {
        for (int x = 0; x < src.cols; x++) {
            float center = padded.at<uchar>(y + padding, x + padding);
            float weight_sum = 0.0f;
            float sum = 0.0f;

            for (int ky = 0; ky < d; ky++) {
                for (int kx = 0; kx < d; kx++) {
                    float neighbor = padded.at<uchar>(y + ky, x + kx);
                    float dy = ky - padding;
                    float dx = kx - padding;
                    float spatial_weight = exp(-(dx * dx + dy * dy) / (2 * sigma_space * sigma_space));
                    float difference = center - neighbor;
                    float intensity_weight = exp(-(difference * difference) / (2 * sigma_color * sigma_color));
                    float weight = intensity_weight * spatial_weight;
                    sum += neighbor * weight;
                    weight_sum += weight;
                }
            }

            destination.at<uchar>(y, x) = saturate_cast<uchar>(sum / weight_sum);
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

    // Mat destination;
    // bilateralFilter(src, destination, 9, 75, 75);
    //
    // imshow("src", src);
    // imshow("bilateral filter", destination);
    // imwrite("bilateral_filter.png", destination);
    //
    // waitKey(0);
    // destroyAllWindows();

    // --------------------------------------------------------------------------------------------

    Mat manual_destination = manualBilateralFilter(src, 9, 75, 75);

    imshow("src", src);
    imshow("manual bilateral filter", manual_destination);
    imwrite("manual bilateral filter.png", manual_destination);
    waitKey(0);
    destroyAllWindows();

    return 0;
}