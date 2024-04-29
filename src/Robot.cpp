#include "Robot.h"


//constructor
Robot::Robot(const Vec3& initialPosition,int maxVelocity,double timeStep,TrajectoryType type)
: position(initialPosition), initialPosition(initialPosition)
, targetPosition(0, 0, 0), unitDirection(0,0,0), quanticCoeffsVar{0,0,0,0,0,0}
, maxVelocity(maxVelocity), timeStep(timeStep), trajType(type)
{
    computeMinimumTime();
    calculateQuanticCoeffs();
}

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


void Robot::computeMinimumTime(){
    // Calculate the distance between the initial position and the target position
    Vec3 distance = this->targetPosition - this->initialPosition;
    // Time calculated assuming instant acceleration to max speed and instant stop
    this->totalTime = distance.magnitude() / maxVelocity;
}

void Robot::calculateQuanticCoeffs() {
    /*
     * Calculate the coefficients of a quantic polynomial for trajectory planning.
     * the quanticCoeffsVar calculated base on the boundry conditions ant t=0 and t=T
     * where T is the total time calculated in the computeMinimumTime function
     * s(0)=0, s'(0)=0, s''(0)=0, s(T)=1, s'(T)=0, s''(T)=0
     */
    quanticCoeffsVar.a0 = 0;
    quanticCoeffsVar.a1 = 0;
    quanticCoeffsVar.a2 = 0;
    quanticCoeffsVar.a3 = 10.0 / pow(totalTime, 3);
    quanticCoeffsVar.a4 = -15.0 / pow(totalTime, 4);
    quanticCoeffsVar.a5 = 6.0 / pow(totalTime, 5);

}

double Robot::calcMotionLaw(double time){

    double s= quanticCoeffsVar.a0 + quanticCoeffsVar.a1 * time + quanticCoeffsVar.a2 * pow(time, 2) + quanticCoeffsVar.a3 * pow(time, 3) + quanticCoeffsVar.a4 * pow(time, 4) + quanticCoeffsVar.a5 * pow(time, 5);
    return s;
}

Vec3 Robot::trajectoryPlanning(double time)
{

    if(trajType==Line)
    {
         double u=calcMotionLaw(time);
         position= initialPosition + u*(targetPosition-initialPosition);
    }
    else
    {
        //not support other trajectories except for straight line
        std::cout<<"Trajectory type not supported"<<std::endl;
        return Vec3{0,0,0};
    }
    return position;
}

void Robot::updatePosition () {

    // Check if the robot is already at the target

    if (isAtTarget()) {
        return;
    }

    // Calculate the total time of the simulation
    computeMinimumTime();
    // Calculate the coefficients of the quantic polynomial
    calculateQuanticCoeffs();

    // Calculate the number of steps
    int nSteps = static_cast<int>(round(totalTime / timeStep));

    // Loop through each step
    for (int i = 0; i <= nSteps; i++) {
        // Calculate the time at each step
        double time = i * timeStep;
        // Calculate the position of the robot at each step
        position = trajectoryPlanning(time);
        // Print the position of the robot at each step
        printPosition(time);
    }

}


void Robot::printPosition(double time) const {

    //printing position with corresponding time side by side
    std::cout << "Time: " << time << " ";
    std::cout << "Robot Position: " << position << std::endl;
}

double Robot::accuracyCheck(){

    //threshold for the error=lastposition-targetposition
    double epsilon = {1e-6};

    computeMinimumTime();
    calculateQuanticCoeffs();

    int lastIndex = static_cast<int>(ceil(totalTime / timeStep))-1;

    double time=lastIndex*timeStep;

    // Calculate the position of the robot at the last step
    Vec3 approxPosition = trajectoryPlanning(time);

    Vec3 error= targetPosition - approxPosition;

    //print that for this time step the error is and the robot will stop at approxPosition
    if(error.magnitude()>epsilon){
        std::cout<<"For time step: "<<timeStep<<" the position error is: "<<error.magnitude()<<" and the robot stopped at: "<<approxPosition<<std::endl;
        //suggest considering a smaller time step to have a more accurate result
        std::cout<<"use smaller time step to have a more accurate result"<<std::endl;
    }




    return error.magnitude();

}

bool Robot::isAtTarget()  {

    atTarget= false;
    double epsilon = 1e-6;
    Vec3 error = targetPosition - position;

    // If the robot is within epsilon distance of the target, return true
    if (error.magnitude() < epsilon) {
        atTarget = true;
        return true;
    }
    return false;
}



