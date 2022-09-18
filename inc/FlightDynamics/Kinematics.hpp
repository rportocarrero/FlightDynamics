#ifndef H_KINEMATICS
#define H_KINEMATICS
#include <vector>
#include "Matrix.hpp"

using namespace std;

vector<float> quaternion_diffeq(vector<float> body_rates, vector<float> quaternions);
vector<float> quaternion_initialization(vector<float> euler_angles);
Matrix direction_cosine_matrix(vector<float> quaterion);
vector<float> euler_angles_from_quaternion(vector<float> quaternion);
vector<float> euler_diffeq(vector<float> body_rates, vector<float> euler_angles);

#endif