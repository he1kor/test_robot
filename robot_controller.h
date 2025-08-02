#ifndef ROBOT_CONTROLLER_H
#define ROBOT_CONTROLLER_H

#include <QObject>
#include <QVector>

#include "robot.h"

#include "test_robots.h"

class RobotController : public QObject{
    Q_OBJECT
    Q_PROPERTY(size_t jointCount READ getNumberOfJoints CONSTANT)
    Q_PROPERTY(const QVector3D lastJointPos READ getLastJointPos NOTIFY lastJointPosChanged)
public:
    explicit RobotController(QObject* parent = nullptr);
    const QVector3D getLastJointPos() const;
    const size_t getNumberOfJoints() const;
public slots:
    void setJointAngles(const QList<double> &angles);
signals:
    void lastJointPosChanged();
private:
    Robot robot = Robot(DEFAULT_6JOINTS);
};

#endif // ROBOT_CONTROLLER_H
