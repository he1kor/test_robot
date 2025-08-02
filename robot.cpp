#include "robot.h"

#include <stdexcept>


void Robot::setRawTheta(size_t jointIndex, double thetaDegrees){
    joints.at(jointIndex).setTheta(thetaDegrees);
}

void Robot::calculatePoses(size_t jointIndex){
    forwardKinematics(joints, std::next(std::begin(joints), jointIndex));
}

void Robot::setTheta(size_t jointIndex, double thetaDegrees){
    setRawTheta(jointIndex, thetaDegrees);
    calculatePoses(jointIndex);
}

size_t Robot::getNumberOfJoints() const{
    return joints.size();
}

QVector3D Robot::getPosition(size_t jointIndex) const{
    return joints.at(jointIndex).getPosition();
}

double Robot::getTheta(size_t jointIndex) const{
    return joints.at(jointIndex).getTheta();
}

DHModel Robot::getDHModel(size_t jointIndex) const{
    return joints.at(jointIndex).getDH();
}

QVector3D Robot::getLastJointPosition() const{
    return joints.back().getPosition();
}
