#ifndef BACKEND_CORE_H
#define BACKEND_CORE_H

#include <QObject.h>

#include "robot_controller.h"

class BackendCore : public QObject{
    Q_OBJECT
    Q_PROPERTY(RobotController* robotController READ getRobotController CONSTANT)
public:
    explicit BackendCore(QObject* parent = nullptr);
    RobotController* getRobotController(){return &robotController;}
private:
    RobotController robotController;
};


#endif // BACKEND_CORE_H
