#include "Robot.h"


//constructor
Robot::Robot(const Vec3& initialPosition,int maxVelocity,double timeStep)
: position(initialPosition),initialPosition(initialPosition),targetPosition(0, 0, 0), unitDirection(0,0,0), maxVelocity(maxVelocity), timeStep(timeStep)
{}

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

void Robot::setTargetPosition(Vec3& targetPosition)
{
    this->targetPosition=targetPosition;

    this->unitDirection = (targetPosition - initialPosition).normalize();
}

void Robot::updatePosition() {

    const double epsilon = 1e-6;
    Vec3 error = targetPosition - position;

    // If the robot is within epsilon distance of the target, just move it to the target
    if (error.magnitude() < epsilon) {
        position = targetPosition;
        return;
    }

    // Calculate the direction of the robot which is heading towards the target
    Vec3 direction = this->unitDirection;
    // Calculate the velocity of the robot
    Vec3 velocity = direction * maxVelocity;
    // Calculate the displacement of the robot at each time step
    Vec3 displacement = velocity * timeStep;

    // move the robot to the new position
    position = position + displacement;
    
}

void Robot::printPosition() const {

    std::cout << "Robot Position: " << position << std::endl;
}

bool Robot::isAtTarget() const {

    const double epsilon = 1e-6;
    Vec3 error = targetPosition - position;

    // If the robot is within epsilon distance of the target, return true
    if (error.magnitude() < epsilon) {
        return true;
    }
}

