#ifndef RECONSTRUCTION_H
#define RECONSTRUCTION_H
#include <vector>

using namespace std;

class Reconstruction {
    public:
        Reconstruction();
        void run_structure_from_motion();
private:
    vector<double> cloud_data;
};


#endif