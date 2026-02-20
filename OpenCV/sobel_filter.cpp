#include <opencv2/opencv.hpp>
#include <iostream>
#include <algorithm>

using namespace std;

// Reference for cv::Mat
// https://docs.opencv.org/4.x/d6/d6d/tutorial_mat_the_basic_image_container.html
// https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html

int main() {
    // 1. Load image in grayscale
    // cv::Mat -> Store the actual data (pixels / numbers) & Be used for general matrices (filters, transforms, feature descriptors)

    cv::Mat src = cv::imread("input.jpg", cv::IMREAD_GRAYSCALE);

    if (src.empty()) {
        std::cout << "Image load failed! Please check the file path." << std::endl;
        return -1;
    }

    // 2. Output matrices (8-bit) for visualization
    cv::Mat gx_img = cv::Mat::zeros(src.size(), CV_8UC1);
    cv::Mat gy_img = cv::Mat::zeros(src.size(), CV_8UC1);
    cv::Mat mag_img = cv::Mat::zeros(src.size(), CV_8UC1);

    cout << "Input -> (width, height) = " << src.size() << endl;
    cout << "Input -> The total number of pixels = width * height = " << src.total() << endl;

    // 3. Sobel kernels
    int kx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int ky[3][3] = {
        {-1, -2, -1},
        { 0,  0,  0},
        { 1,  2,  1}
    };

    // 4. Convolution (direct pointer access)
    for (int y = 1; y < src.rows - 1; y++) {
        const uchar* prev = src.ptr<uchar>(y - 1);
        const uchar* curr = src.ptr<uchar>(y);
        const uchar* next = src.ptr<uchar>(y + 1);

        uchar* out_gx = gx_img.ptr<uchar>(y);
        uchar* out_gy = gy_img.ptr<uchar>(y);
        uchar* out_mag = mag_img.ptr<uchar>(y);

        for (int x = 1; x < src.cols - 1; x++) {
            // Compute Gx (Sobel X)
            int gx =
                (prev[x - 1] * kx[0][0]) + (prev[x] * kx[0][1]) + (prev[x + 1] * kx[0][2]) +
                (curr[x - 1] * kx[1][0]) + (curr[x] * kx[1][1]) + (curr[x + 1] * kx[1][2]) +
                (next[x - 1] * kx[2][0]) + (next[x] * kx[2][1]) + (next[x + 1] * kx[2][2]);

            // Compute Gy (Sobel Y)
            int gy =
                (prev[x - 1] * ky[0][0]) + (prev[x] * ky[0][1]) + (prev[x + 1] * ky[0][2]) +
                (curr[x - 1] * ky[1][0]) + (curr[x] * ky[1][1]) + (curr[x + 1] * ky[1][2]) +
                (next[x - 1] * ky[2][0]) + (next[x] * ky[2][1]) + (next[x + 1] * ky[2][2]);

            int ax = std::abs(gx);
            int ay = std::abs(gy);

            // Magnitude (L2). L1 alternative: ax + ay
            int mag = static_cast<int>(std::sqrt(static_cast<double>(gx) * gx + static_cast<double>(gy) * gy));

            // Clamp to [0, 255]
            out_gx[x] = static_cast<uchar>(std::min(std::max(ax, 0), 255));
            out_gy[x] = static_cast<uchar>(std::min(std::max(ay, 0), 255));
            out_mag[x] = static_cast<uchar>(std::min(std::max(mag, 0), 255));
        }
    }

    cv::imshow("Original", src);
    cv::imshow("Sobel Gx", gx_img);
    cv::imshow("Sobel Gy", gy_img);
    cv::imshow("Sobel Magnitude", mag_img);
    cv::waitKey(0);

    return 0;
}
