#include "Robot.h"


//constructor
Robot::Robot(const std::vector<double>& initialPosition,int maxVelocity,int timeStep)
: position(initialPosition), maxVelocity(maxVelocity), timeStep(timeStep)
{}

//Getter Methods
std::vector<double> Robot::getPosition() const
{
    return position;
}

int Robot::getTimeStep() const
{
    return timeStep;
}

int Robot::getmaxVelocity() const
{
    return maxVelocity;
}

void Robot::setTargetPosition(const std::vector<double>& setTargetPosition)
{
    this->targetPosition=targetPosition;
}

