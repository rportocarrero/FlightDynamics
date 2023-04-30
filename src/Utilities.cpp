#include "Utilities.hpp"
#include "Matrix.hpp"
#include <cmath>

vector<float> Transformation_Heliocentric_wrt_Inertial(vector<float> heliocentric, float obliquity){
    Matrix T;
    T.rows = 3;
    T.cols = 3;
    T.data = {{1,0,0},{0,cos(obliquity), sin(obliquity)},{0, -sin(obliquity), cos(obliquity)}};

    return Matrix_vector_product(T,heliocentric);
}; 