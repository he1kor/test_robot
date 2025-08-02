#ifndef ROBOT_H
#define ROBOT_H

#include <QVector3D>
#include <QObject.h>

#include "dh_model.h"

template<typename Container>
concept Iterable = requires(Container c) {
    c.size();
    c.begin();
    c.end();
};

class Robot{
public:
    template<Iterable Container>
    requires std::same_as<typename Container::value_type, DHModel>
    Robot(const Container& dh_model){
        joints.reserve(dh_model.size());
        for (const DHModel& dh_model_row : dh_model){
            joints.push_back(Joint(dh_model_row));
        }
    }

    void setTheta(size_t jointIndex, double thetaDegrees);

    template<Iterable Container>
    requires std::same_as<typename Container::value_type, double>
    QVector3D setThetaValues(const Container& thetaDegrees){
        if (thetaDegrees.size() != getNumberOfJoints())
            throw std::invalid_argument(
                std::format("thetaDegrees size doesn't match number of joints: {} (number of joints: {})",
                            thetaDegrees.size(),
                            getNumberOfJoints())
                );
        size_t i = 0;
        for (auto it = thetaDegrees.begin(); it != thetaDegrees.end(); ++it, ++i){
            setRawTheta(i, *it);
        }
        calculatePoses(0);
        return getLastJointPosition();
    }

    size_t getNumberOfJoints() const;
    QVector3D getPosition(size_t jointIndex) const;
    double getTheta(size_t jointIndex) const;
    DHModel getDHModel(size_t jointIndex) const;
    QVector3D getLastJointPosition() const;
private:
    void setRawTheta(size_t jointIndex, double thetaDegrees);
    void calculatePoses(size_t jointIndex);
    std::vector<Joint> joints;
};

#endif // ROBOT_H
