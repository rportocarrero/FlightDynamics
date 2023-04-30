#include "Kinematics.hpp"
#include <cmath>
#include <math.h>
#include <tgmath.h>

vector<float> quaternion_diffeq(vector<float> body_rates, vector<float> quaternion){
    if(body_rates.size() != 3 || quaternion.size() != 4){
        throw "invalid input size";
    }

    float p = body_rates[0];
    float q = body_rates[1];
    float r = body_rates[2];

    float q0 = quaternion[0];
    float q1 = quaternion[1];
    float q2 = quaternion[2];
    float q3 = quaternion[3];

    float q0_dot = (-p * q1 -q * q2 -r * q3) / 2;
    float q1_dot = (p * q0 + r * q2 -q * q3) / 2;
    float q2_dot = (q * q0 -r * q1 + p * q3) / 2;
    float q3_dot = (r * q0 + q * q1 - p * q2) / 2;

    vector<float> result = {q0_dot, q1_dot, q2_dot, q3_dot};
    return result;
}

vector<float> quaternion_initialization(vector<float> euler_angles){
    if(euler_angles.size() != 3)(
        throw "invalid input"
    );

    float roll = euler_angles[0];
    float pitch = euler_angles[1];
    float yaw = euler_angles[2];

    float q0 = cos(yaw/2)*cos(pitch/2)*cos(roll/2) + sin(yaw/2)*sin(pitch/2)*sin(roll/2);
    float q1 = cos(yaw/2)*cos(pitch/2)*sin(roll/2) - sin(yaw/2)*sin(pitch/2)*cos(roll/2);
    float q2 = cos(yaw/2)*sin(pitch/2)*cos(roll/2) + sin(yaw/2)*cos(pitch/2)*sin(roll/2);
    float q3 = sin(yaw/2)*cos(pitch/2)*cos(roll/2) - cos(yaw/2)*sin(pitch/2)*sin(roll/2);

    vector<float> result = {q0, q1, q2, q3};
    return result;
}

Matrix direction_cosine_matrix(vector<float> quaternion){
    if(quaternion.size() != 4){
        throw "invalid input";
    }
    float q0 = quaternion[0];
    float q1 = quaternion[1];
    float q2 = quaternion[2];
    float q3 = quaternion[3];


    Matrix result;
    result.rows = 3;
    result.cols = 3;
    result.is_square = 1;

    float T00 = pow(q0,2) + pow(q1,2) - pow(q2,2) - pow(q3,3);
    float T01 = 2*(q1*q2 + q0*q3);
    float T02 = 2*(q1*q3 + q0*q2);
    float T10 = 2*(q1*q2 + q0*q3);
    float T11 = pow(q0,2) - pow(q1,2) + pow(q2,2) - pow(q3,2);
    float T12 = 2*(q2*q3 + q0*q1);
    float T20 = 2*(q1*q3 + q0*q2);
    float T21 = 2*(q2*q3 - q0*q1);
    float T22 = pow(q0,2) - pow(q1,2) - pow(q2,2) + pow(q3,2);

    result.data = {{T00, T01, T02},{T10, T11, T12},{T20, T21, T22}};
    return result;
}

vector<float> euler_angles_from_quaternion(vector<float> quaternion){
    if(quaternion.size() != 4){
        throw "invalid input";
    }

    float q0 = quaternion[0];
    float q1 = quaternion[1];
    float q2 = quaternion[2];
    float q3 = quaternion[3];
    
    float yaw = atan((2*(q1*q2 - q0*q3)) / (pow(q0,2) + pow(q1,2) - pow(q2,2) - pow(q3,2)));
    float pitch = asin(-2*(q1*q3-q0*q2));
    float roll = atan((2*(q2*q3 + q0*q1))/(pow(q0,2) - pow(q1,2) - pow(q2,2) + pow(q3,2)));

    vector<float> result = {yaw, pitch, roll};
    return result;
}

vector<float> euler_diffeq(vector<float> body_rates, vector<float> euler_angles){
    if(body_rates.size() != 3 || euler_angles.size() != 3){
        throw "invalid inputs";
    }

    float p = body_rates[0];
    float q = body_rates[1];
    float r = body_rates[2];

    float yaw = euler_angles[0];
    float pitch = euler_angles[1];
    float roll = euler_angles[2];

    float roll_dot = p + q*(sin(roll)*tan(pitch)) + r*(cos(roll)*tan(pitch));
    float pitch_dot = q*cos(roll) - r*sin(roll);
    float yaw_dot = q*sin(roll)*cos(pitch) + r*cos(roll)/cos(pitch);

    vector<float> result = {roll_dot, pitch_dot, yaw_dot};
    return result;
}