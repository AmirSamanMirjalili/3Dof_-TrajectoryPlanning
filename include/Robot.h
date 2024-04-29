#pragma once
#include <cmath> // For sqrt function
#include "Vec3.h"

// Define a struct to store the coefficients of a quantic polynomial for trajectory planning
 struct quanticCoeffs{
        double a0,a1,a2,a3,a4,a5;
    };

//trajectry types
enum TrajectoryType
{
    Line, // straight line
    //Circle, // circle
};

class Robot
{
public:
    Robot(const Vec3& initialPosition, int maxVelocity,double timeStep,TrajectoryType type);  //constructor
    
    //Getter Methods
    Vec3 getPosition() const;
    int getmaxVelocity() const;
    double getTimeStep() const;

    //Setter Methods
    void setTargetPosition(Vec3& targetPosition);
    
    // utility Methods
    void computeMinimumTime();
    void calculateQuanticCoeffs();
    void updatePosition();
    bool isAtTarget() ;
    void printPosition() const;


private:
    //private data members
    Vec3 position;
    Vec3 initialPosition;
    Vec3 targetPosition;
    Vec3 unitDirection;
    int maxVelocity;
    double totalTime;
    double timeStep;
    bool atTarget;
    quanticCoeffs quanticCoeffsVar;
    TrajectoryType trajType;

    //private methods
    double calcMotionLaw(double time);
    Vec3 trajectoryPlanning(double time);
   
    
};



