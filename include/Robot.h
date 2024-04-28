#pragma once
#include <vector>
#include <cmath> // For sqrt function


class Robot
{
public:
    Robot(const std::vector<double>& initialPosition, int maxVelocity,int timeStep);  //constructor
    
    //Getter Methods
    std::vector<double> getPosition() const;
    int getmaxVelocity() const;
    int getTimeStep() const;

    //Setter Methods
    void setTargetPosition(const std::vector<double>& targetPosition);
    
    // utility methods
    void updatePosition();
    bool isAtTarget() const;
    void printPosition() const;


private:
    std::vector<double> position;
    std::vector<double> targetPosition;
    int maxVelocity;
    int timeStep;
};



