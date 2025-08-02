#include "dh_model.h"


QMatrix4x4 computeDHMatrix(const DHModel &params){
    double theta_rad = toRad(params.theta_deg);
    double cos_theta = cos(theta_rad);
    double sin_theta = sin(theta_rad);
    double cos_alpha = cos(params.alpha_rad);
    double sin_alpha = sin(params.alpha_rad);

    QMatrix4x4 matrix;
    matrix(0, 0) = cos_theta;
    matrix(0, 1) = -sin_theta * cos_alpha;
    matrix(0, 2) = sin_theta * sin_alpha;
    matrix(0, 3) = params.a * cos_theta;

    matrix(1, 0) = sin_theta;
    matrix(1, 1) = cos_theta * cos_alpha;
    matrix(1, 2) = -cos_theta * sin_alpha;
    matrix(1, 3) = params.a * sin_theta;

    matrix(2, 0) = 0;
    matrix(2, 1) = sin_alpha;
    matrix(2, 2) = cos_alpha;
    matrix(2, 3) = params.d;

    matrix(3, 0) = 0;
    matrix(3, 1) = 0;
    matrix(3, 2) = 0;
    matrix(3, 3) = 1;

    return matrix;
}
