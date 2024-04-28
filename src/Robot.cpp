#include "Robot.h"


//constructor
Robot::Robot(const std::vector<int>& initialPosition,int maxVelocity,int timeStep)
: position(initialPosition), maxVelocity(maxVelocity), timeStep(timeStep)
{}

//Getter Methods
std::vector<int> Robot::getPosition() const
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

