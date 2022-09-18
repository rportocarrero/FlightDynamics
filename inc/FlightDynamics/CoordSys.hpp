#ifndef H_COORD_SYS
#define H_COORD_SYS

Matrix heliocentric_wrt_inertial(float obliquity);
Matrix earth_wrt_inertial(float hour_angle);
Matrix geocentric_wrt_earth(float longitude, float lattitude);
Matrix geodetic_wrt_geocentric(float geodetic_lattitude, float geocentric_lattitude);
Matrix body_wrt_geo(float yaw, float pitch, float roll);
Matrix wind_wrt_stability(float beta);
Matrix body_wrt_stability(float alpha);
Matrix wind_wrt_body(float alpha, float beta);
Matrix aeroballistic_wrt_aeroballistic_wind(float total_aoa);
Matrix body_wrt_aeroballistic(float aero_roll_angle);
Matrix aeroballistic_wind_wrt_body(float total_aoa, float aero_roll_angle);
Matrix flightpath_wrt_geo(float heading_angle, float flightpath_angle);
Matrix body_wrt_local_level(float yaw, float pitch, float roll);
#endif