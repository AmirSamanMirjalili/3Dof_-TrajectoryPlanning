#pragma once
#include <vector>


class Robot
{
public:
    Robot(const std::vector<int>& initialPosition, int maxVelocity,int timeStep);  //constructor
    
    //Getter Methods
    std::vector<int> getPosition() const;
    int getmaxVelocity() const;
    int getTimeStep() const;

private:
    std::vector<int> position;
    int maxVelocity;
    int timeStep;
};



