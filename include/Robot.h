#pragma once
#include <cmath> // For sqrt function
#include "Vec3.h"


class Robot
{
public:
    Robot(const Vec3& initialPosition, int maxVelocity,double timeStep);  //constructor
    
    //Getter Methods
    Vec3 getPosition() const;
    int getmaxVelocity() const;
    double getTimeStep() const;

    //Setter Methods
    void setTargetPosition(Vec3& targetPosition);
    
    // utility methods
    void updatePosition();
    bool isAtTarget() const;
    void printPosition() const;


private:
    Vec3 position;
    Vec3 targetPosition;
    int maxVelocity;
    double timeStep;
};



