#include "Robot.h"


//constructor
Robot::Robot(const Vec3& initialPosition,int maxVelocity,double timeStep)
: position(initialPosition),targetPosition(0, 0, 0), maxVelocity(maxVelocity), timeStep(timeStep){}

//Getter Methods
Vec3 Robot::getPosition() const
{
    return position;
}

double Robot::getTimeStep() const
{
    return timeStep;
}

int Robot::getmaxVelocity() const
{
    return maxVelocity;
}

void Robot::setTargetPosition(Vec3& setTargetPosition)
{
    this->targetPosition=targetPosition;
}

