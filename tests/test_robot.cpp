#include "gtest/gtest.h"
#include "Robot.h"

TEST(RobotConstructor, InitializesCorrectly) {
    std::vector<int> initialPosition = {0,0,0};
    int maxVelocity {10};
    int timeStep {1};

    Robot robot(initialPosition, maxVelocity, timeStep);


    EXPECT_EQ(robot.getPosition(), initialPosition);
    EXPECT_EQ(robot.getmaxVelocity(), maxVelocity);
    EXPECT_EQ(robot.getTimeStep(), timeStep);
    

}