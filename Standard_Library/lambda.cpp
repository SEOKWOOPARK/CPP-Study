#include <iostream>
#include <vector>
using namespace std;


bool compare(int a, int b) {
    return a > b;
}

void AdaptiveThreshold::UpdateModelDeviation(const Sophus::SE3d &current_deviation) {
    const double model_error = [&]() {
        const double theta = Eigen::AngleAxisd(current_deviation.rotationMatrix()).angle();
        const double delta_rot = 2.0 * max_range_ * std::sin(theta / 2.0);
        const double delta_trans = current_deviation.translation().norm();
        return delta_trans + delta_rot;
    }();
    if (model_error > min_motion_threshold_) {
        model_sse_ += model_error * model_error;
        num_samples_++;
    }
}


int main() {
    // Vector conception (allow to store a sequence of elements like int, double, string)
    // From STL. Dynamic sizing, Type-safe

    vector<int> v = {1, 2, 3, 4};

    v.push_back(5);
    v.push_back(6);

    for (int val: v) {
        cout << val << " ";
    }

    cout << endl;
    v.pop_back();


    for (int val: v) {
        cout << val << " ";
    }

    cout << endl;
    v[0] = 100;

    for (int val: v) {
        cout << val << " ";
    }

    cout << endl;

    v.clear();
    cout << v.size() << endl;

    cout << "-------------------------" << endl;
    vector<int> src = {1, 2, 3, 4, 5};
    vector<int> dst;

    for(int i = 0; i < src.size(); i++) {
        dst.emplace_back(src[i] * 2);
    }

    for (int i = 0; i < dst.size(); i++) {
        cout << dst[i] << endl;
    }

    cout << "-------------------------" << endl;

    vector<int> numbers1 = {4, 1, 3, 9, 7, 5, 8};
    vector<int> numbers2 = {4, 1, 30, 90, 7, 5, 8};
    vector<int> numbers3 = {200, 1, 30, 90, 7, 5, 8};

    sort(numbers1.begin(), numbers1.end(), compare);
    cout << "Sorting by a general way" << endl;

    for (int num: numbers1) {
        cout << num << " ";
    }

    cout << endl;
    cout << "Sorting by lambda expression" << endl;
    sort(numbers2.begin(), numbers2.end(), [](int a, int b) -> bool {return a > b; });

    for (int num: numbers2) {
        cout << num << " ";
    }

    cout << endl;
    cout << "Sorting by lambda expression" << endl;
    auto decending_order = [](int a, int b) { return a > b; };
    sort(numbers3.begin(), numbers3.end(), decending_order);

    for (int num: numbers3) {
        cout << num << " ";
    }

    return 0;
}