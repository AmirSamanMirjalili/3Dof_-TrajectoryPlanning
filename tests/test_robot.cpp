#include "Robot.h"
#include "gtest/gtest.h"


TEST(RobotClass, InitializesCorrectly) {
    Vec3 initialPosition(0,0,0);
    int maxVelocity {10};
    double timeStep {1};

    Robot robot(initialPosition, maxVelocity, timeStep, TrajectoryType::Line);

    EXPECT_EQ(robot.getPosition(), initialPosition);
    EXPECT_EQ(robot.getmaxVelocity(), maxVelocity);
    EXPECT_EQ(robot.getTimeStep(), timeStep);
    
}

TEST(RobotClass, UpdatePositionTest) {
    // Arrange
    Vec3 initialPosition(0, 0, 0);
    Vec3 targetPosition(10, 0, 0);
    int maxVelocity = 5;
    double timeStep = 0.5;
    Robot robot(initialPosition, maxVelocity, timeStep, TrajectoryType::Line);
    robot.setTargetPosition(targetPosition);

    // Act
    robot.updatePosition();

    // Assert
    Vec3 expectedPosition = targetPosition; // Assuming the robot should reach the target position
    Vec3 actualPosition = robot.getPosition();
    EXPECT_EQ(actualPosition, expectedPosition);
}





 TEST(Vec3Test, Addition) {
     Vec3 v1(1.0, 2.0, 3.0);
     Vec3 v2(4.0, 5.0, 6.0);
     Vec3 result = v1 + v2;

     EXPECT_EQ(result.x, 5.0);
     EXPECT_EQ(result.y, 7.0);
     EXPECT_EQ(result.z, 9.0);
 }

 TEST(Vec3Test, Subtraction) {
     Vec3 v1(4.0, 5.0, 6.0);
     Vec3 v2(1.0, 2.0, 3.0);
     Vec3 result = v1 - v2;

     EXPECT_DOUBLE_EQ(result.x, 3.0);
     EXPECT_DOUBLE_EQ(result.y, 3.0);
     EXPECT_DOUBLE_EQ(result.z, 3.0);
 }

 TEST(Vec3Test, ScalarMultiplication) {
     Vec3 v(1.0, 2.0, 3.0);
     Vec3 result = v * 2.0;

     EXPECT_DOUBLE_EQ(result.x, 2.0);
     EXPECT_DOUBLE_EQ(result.y, 4.0);
     EXPECT_DOUBLE_EQ(result.z, 6.0);
 }

 TEST(Vec3Test, Equality) {
     Vec3 a(1, 2, 3);
     Vec3 b(1, 2, 3);
     EXPECT_EQ(a, b);
 }

 TEST(Vec3Test,normailize) {
     Vec3 v(1.0, 2.0, 3.0);
     Vec3 result = v.normalize();
     double magnitude = result.magnitude();
     EXPECT_DOUBLE_EQ(magnitude, 1.0);
 }

 