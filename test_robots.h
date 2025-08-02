#ifndef TEST_ROBOTS_H
#define TEST_ROBOTS_H

#include <vector>
#include <cmath>
#include "dh_model.h"

const std::vector<DHModel> DEFAULT_6JOINTS = {
    // Kinematics    theta (deg)   a(m)      d(m)        alpha(rad)
    /* Joint 0 */ {  15.0,         0.0,      0.213,      M_PI/2 },
    /* Joint 1 */ { -50.0,        -0.8,      0.193,      0.0    },
    /* Joint 2 */ { -60.0,        -0.590,   -0.16,       0.0    },
    /* Joint 3 */ {  95.0,         0.0,      0.25,       M_PI/2 },
    /* Joint 4 */ {  50.0,         0.0,      0.28,      -M_PI/2 },
    /* Joint 5 */ {   0.0,         0.0,      0.25,       0.0    }
};

#endif // TEST_ROBOTS_H
