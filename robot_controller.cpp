#include "robot_controller.h"

const QVector3D RobotController::getLastJointPos() const{
    return robot.getLastJointPosition();
}

const size_t RobotController::getNumberOfJoints() const{
    return robot.getNumberOfJoints();
}

RobotController::RobotController(QObject *parent) : QObject(parent){}

void RobotController::setJointAngles(const QList<double>& angles){
    robot.setThetaValues(angles);
    emit lastJointPosChanged();
}
