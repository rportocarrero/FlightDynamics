#include "Matrix.hpp"
#include "CoordSys.hpp"
#include <cmath>

Matrix heliocentric_wrt_inertial(float obliquity){
    Matrix result;
    result.rows = 3;
    result.cols = 3;
    result.is_square = 1;
    
    vector<vector<float>> tm(result.rows, vector<float>(result.cols, 0));
    tm[1][1] = cos(obliquity);
    tm[1][2] = sin(obliquity);
    tm[2][1] = -sin(obliquity);
    tm[2][2] = cos(obliquity);

    result.data = tm;
    return result;
}

Matrix earth_wrt_inertial(float hour_angle){
    Matrix result;
    result.rows = 3;
    result.cols = 3;
    result.is_square = 1;
    
    vector<vector<float>> tm(result.rows, vector<float>(result.cols, 0));
    tm[0][0] = cos(hour_angle);
    tm[0][1] = sin(hour_angle);
    tm[1][0] = -sin(hour_angle);
    tm[1][1] = cos(hour_angle);

    result.data = tm;
    return result;
}

Matrix geocentric_wrt_earth(float longitude, float lattitude){
    Matrix result;
    result.rows = 3;
    result.cols = 3;
    result.is_square = 1;
    
    vector<vector<float>> tm(result.rows, vector<float>(result.cols, 0));
    tm[0][0] = -sin(lattitude) * cos(longitude);
    tm[0][1] = -sin(lattitude) * sin(longitude);
    tm[0][2] = cos(lattitude);
    tm[1][0] = -sin(longitude);
    tm[1][1] = cos(longitude);
    tm[2][0] = -cos(lattitude) * cos(longitude);
    tm[2][1] = -cos(lattitude) * sin(longitude);
    tm[2][2] = -sin(lattitude);

    result.data = tm;
    return result;
}

Matrix geodetic_wrt_geocentric(float geodetic_lattitude, float geocentric_lattitude){
    float deflection_angle = geocentric_lattitude - geodetic_lattitude;
    Matrix result;
    result.rows = 3;
    result.cols = 3;
    result.is_square = 1;
    
    vector<vector<float>> tm(result.rows, vector<float>(result.cols, 0));
    tm[0][0] = cos(deflection_angle);
    tm[0][2] = sin(deflection_angle);
    tm[1][1] = 1;
    tm[2][0] = -sin(deflection_angle);
    tm[2][2] = cos(deflection_angle);

    result.data = tm;
    return result;
}

Matrix body_wrt_geo(float yaw, float pitch, float roll){
    Matrix result;
    result.rows = 3;
    result.cols = 3;
    result.is_square = 1;
    
    vector<vector<float>> tm(result.rows, vector<float>(result.cols, 0));
    tm[0][0] = cos(yaw) * cos(pitch);
    tm[0][1] = sin(yaw) * cos(pitch);
    tm[0][2] = -sin(pitch);
    tm[1][0] = cos(yaw) * sin(pitch) * sin(roll) - sin(pitch) * cos(roll);
    tm[1][1] = sin(yaw) * sin(pitch) * sin(roll) + cos(yaw) * cos(roll);
    tm[1][2] = cos(pitch) * sin(roll);
    tm[2][0] = cos(yaw) * sin(pitch) * cos(roll) + sin(yaw) * sin(roll);
    tm[2][1] = sin(yaw) * sin(pitch) * cos(roll) - cos(yaw) * sin(roll);
    tm[2][2] = cos(pitch) * cos(roll);

    result.data = tm;
    return result;
}

Matrix wind_wrt_stability(float beta){
    Matrix result;
    result.rows = 3;
    result.cols = 3;
    result.is_square = 1;
    
    vector<vector<float>> tm(result.rows, vector<float>(result.cols, 0));
    tm[0][0] = cos(beta);
    tm[0][1] = sin(beta);
    tm[1][0] = -sin(beta);
    tm[1][1] = cos(beta);
    tm[2][2] = 1;

    result.data = tm;
    return result;
}

Matrix body_wrt_stability(float alpha){
    Matrix result;
    result.rows = 3;
    result.cols = 3;
    result.is_square = 1;
    
    vector<vector<float>> tm(result.rows, vector<float>(result.cols, 0));
    tm[0][0] = cos(alpha);
    tm[0][2] = -sin(alpha);
    tm[1][0] = 1;
    tm[2][0] = sin(alpha);
    tm[2][2] = cos(alpha);

    result.data = tm;
    return result;
}

Matrix wind_wrt_body(float alpha, float beta){
    Matrix result;
    result.rows = 3;
    result.cols = 3;
    result.is_square = 1;
    
    vector<vector<float>> tm(result.rows, vector<float>(result.cols, 0));
    tm[0][0] = cos(alpha) * cos(beta);
    tm[0][1] = sin(beta);
    tm[0][2] = sin(alpha) * cos(beta);
    tm[1][0] = -cos(alpha) * sin(beta);
    tm[1][1] = cos(beta);
    tm[1][2] = -sin(alpha) * sin(beta);
    tm[2][0] = -sin(alpha);
    tm[2][2] = cos(alpha);

    result.data = tm;
    return result;
}

Matrix aeroballistic_wrt_aeroballistic_wind(float total_aoa){
    Matrix result;
    result.rows = 3;
    result.cols = 3;
    result.is_square = 1;
    
    vector<vector<float>> tm(result.rows, vector<float>(result.cols, 0));
    tm[0][0] = cos(total_aoa);
    tm[0][2] = -sin(total_aoa);
    tm[1][1] = 1;
    tm[2][0] = sin(total_aoa);
    tm[2][2] = cos(total_aoa);

    result.data = tm;
    return result;
}

Matrix body_wrt_aeroballistic(float aero_roll_angle){
    Matrix result;
    result.rows = 3;
    result.cols = 3;
    result.is_square = 1;
    
    vector<vector<float>> tm(result.rows, vector<float>(result.cols, 0));
    tm[0][0] = 1;
    tm[1][1] = cos(aero_roll_angle);
    tm[1][2] = sin(aero_roll_angle);
    tm[2][1] = -sin(aero_roll_angle);
    tm[2][2] = cos(aero_roll_angle);

    result.data = tm;
    return result;
}

Matrix aeroballistic_wind_wrt_body(float total_aoa, float aero_roll_angle){
    Matrix result;
    result.rows = 3;
    result.cols = 3;
    result.is_square = 1;
    
    vector<vector<float>> tm(result.rows, vector<float>(result.cols, 0));
    tm[0][0] = cos(total_aoa);
    tm[0][1] = sin(total_aoa) * sin(aero_roll_angle);
    tm[0][2] = sin(total_aoa) * cos(aero_roll_angle);
    tm[1][1] = cos(aero_roll_angle);
    tm[1][2] = -sin(aero_roll_angle);
    tm[2][0] = -sin(total_aoa);
    tm[2][1] = cos(total_aoa) * sin(aero_roll_angle);
    tm[2][2] = cos(total_aoa) * cos(aero_roll_angle);

    result.data = tm;
    return result;
}

Matrix flightpath_wrt_geo(float heading_angle, float flightpath_angle){
    Matrix result;
    result.rows = 3;
    result.cols = 3;
    result.is_square = 1;
    
    vector<vector<float>> tm(result.rows, vector<float>(result.cols, 0));
    tm[0][0] = cos(flightpath_angle) * cos(heading_angle);
    tm[0][1] = cos(flightpath_angle) * sin(heading_angle);
    tm[0][2] = -sin(flightpath_angle);
    tm[1][0] = -sin(heading_angle);
    tm[1][1] = cos(heading_angle);
    tm[2][0] = sin(flightpath_angle) * cos(heading_angle);
    tm[2][1] = sin(flightpath_angle) * sin(heading_angle);
    tm[2][2] = cos(flightpath_angle);

    result.data = tm;
    return result;
}