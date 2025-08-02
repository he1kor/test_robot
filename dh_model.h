#ifndef DH_MODEL_H
#define DH_MODEL_H

#include <cmath>
#include <QMatrix4x4>

inline double toRad(double degrees) {
    return degrees * M_PI / 180.0;
}

struct DHModel {
    double theta_deg;
    double a;
    double d;
    double alpha_rad;
};

class Joint{
public:
    Joint(DHModel dh_model) : dh_model(dh_model){}
    QVector3D getPosition() const{return position;}
    double getTheta() const{return dh_model.theta_deg;}
    void setPosition(QVector3D position){this->position = position;}
    void setTheta(double theta_deg){dh_model.theta_deg = theta_deg;}
    const DHModel& getDH() const {return dh_model;}
private:
    DHModel dh_model;
    QVector3D position = {0.0, 0.0, 0.0};
};

QMatrix4x4 computeDHMatrix(const DHModel& params);

template <std::ranges::forward_range Range>
requires std::same_as<std::ranges::range_value_t<Range>, Joint>
void forwardKinematics(Range&& range, std::ranges::iterator_t<Range> start){
    QMatrix4x4 transformationMatrix;
    transformationMatrix.setToIdentity();

    for (Joint& joint : std::ranges::subrange(start, std::ranges::end(range))) {
        QMatrix4x4 DH = computeDHMatrix(joint.getDH());
        transformationMatrix *= DH;
        joint.setPosition({
            transformationMatrix(0, 3),
            transformationMatrix(1, 3),
            transformationMatrix(2, 3)
        });
    }
}

#endif // DH_MODEL_H
