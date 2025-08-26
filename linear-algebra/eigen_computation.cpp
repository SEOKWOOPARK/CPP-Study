#include <Eigen/Dense>
#include <iostream>

using namespace std;
using namespace Eigen;

int main() {
    Vector3d v1(1,2,3);
    Matrix<double, 3, 1> v2(3, 4, 5);

    Matrix3d R;
    R << 1, 0, 0,
         0, 1, 0,
         0, 0, 1;

    Vector3d result1 = R * v1;
    Vector3d result2 = R * v2;

    cout << result1 << endl;
    cout << result2 << endl;

    cout << "---------------------------" << endl;
    // Homogeneous Coordinates: Standard for ROS, OpenCL
    // Enabling Integrating rotation and translation in one matrix multiplying

    Matrix3d rotation1 = Matrix3d::Identity();
    Vector3d t(1, 0, 0);

    Matrix4d T = Matrix4d::Identity();

    // Top-left 3 x 3 -> Mapping it with rotation1
    // Top-right 3 x 1 -> Mapping it with translation
    T.block<3, 3>(0, 0) = rotation1;
    T.block<3, 1>(0, 3) = t;
    cout << T << endl;

    cout << "---------------------------" << endl;

    // Rotation
    // M_PI = π
    // M_PI / 2 = π / 2 = 90°
    // Vector3d::Unit -> Basis axis for rotation
    Vector3d p1(1, 0, 0);
    Matrix3d rotation2 = AngleAxisd(M_PI / 2, Vector3d::UnitZ()).toRotationMatrix();
    Matrix3d rotation3 = AngleAxisd(M_PI / 2, Vector3d::UnitX()).toRotationMatrix();
    Matrix3d rotation4 = AngleAxisd(M_PI / 2, Vector3d::UnitY()).toRotationMatrix();
    // AngleAxisd type instance
    AngleAxisd angie_axis_instance(M_PI / 2, Vector3d::UnitZ());
    Vector3d t2(1, 0, 0);;

    Vector3d p_r2_result = rotation2 * p1 + t2;
    Vector3d p_r3_result = rotation3 * p1 + t2;
    Vector3d p_r4_result = rotation4 * p1 + t2;
    cout << p_r2_result.transpose() << endl;
    cout << p_r3_result.transpose() << endl;
    cout << p_r4_result.transpose() << endl;





    cout << "---------------------------" << endl;




}
