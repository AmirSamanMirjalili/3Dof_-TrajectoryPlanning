#include "Robot.h"
    #include "gtest/gtest.h"


TEST(RobotConstructor, InitializesCorrectly) {
    Vec3 initialPosition(0,0,0);
    int maxVelocity {10};
    double timeStep {1};

    Robot robot(initialPosition, maxVelocity, timeStep);

    EXPECT_EQ(robot.getPosition(), initialPosition);
    EXPECT_EQ(robot.getmaxVelocity(), maxVelocity);
    EXPECT_EQ(robot.getTimeStep(), timeStep);
    
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