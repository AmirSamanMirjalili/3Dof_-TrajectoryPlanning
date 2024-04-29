# simple_3dof_object


## Project Overview

This project simulates a simple flying robot that translates in an environment with three degrees of freedom (3 DOF). The robot can move to a target position at a specified maximum velocity, assuming infinite acceleration and no system delays.

To make the robot move toward the target point, we have planned a trajectory with a 5th-order polynomial time series (Read Lynch's Modern Robotics for more details). 

## Robot Class Functionalities

The `Robot` class is designed to simulate the movement of a robot towards a target position using a specific trajectory planning method. Below is a detailed explanation of each method within the `Robot` class:

### `computeMinimumTime()`
This method calculates the minimum time required for the robot to reach its target position from its initial position, assuming instantaneous acceleration to maximum velocity and an immediate stop. The calculation is based on the straight-line distance between the initial and target positions and the robot's maximum velocity.

### `calculateQuanticCoeffs()`
This method computes the coefficients of a quintic (fifth-degree) polynomial used for trajectory planning. The coefficients are determined based on boundary conditions at the start (`t=0`) and end (`t=T`) of the motion, where `T` is the total time computed in `computeMinimumTime()`. The boundary conditions are:
- Position (`s`) is 0 at `t=0` and 1 at `t=T`.
- Velocity (`s'`) and acceleration (`s''`) are 0 at both `t=0` and `t=T`.

The coefficients ensure a smooth trajectory for the robot, with smooth starts and stops.

### `calcMotionLaw(double time)`
This method calculates the position of the robot at a given time based on the quintic polynomial defined by the coefficients calculated in `calculateQuanticCoeffs()`. It returns the normalized position value `s` at the specified time.

### `trajectoryPlanning(double time)`
Depending on the trajectory type (`Line`), this method calculates the robot's position at a given time using the motion law from `calcMotionLaw()`. If the trajectory type is not supported, it returns a zero vector and prints an error message.

### `updatePosition()`
This method updates the robot's position over time until it reaches the target. It first checks if the robot is already at the target. If not, it computes the minimum time and quintic coefficients, then iteratively calculates the robot's position at each time step until the target is reached, printing the position at each step.

### `printPosition(double time)`
Prints the robot's position alongside the corresponding time, providing a timestamped log of the robot's trajectory.

These methods collectively enable the simulation of a robot moving in a 2D space towards a target position, using a predefined trajectory type and handling the calculations necessary for realistic motion simulation.

## Objectives

- **Initialization**: At the start, the user sets the initial position, maximum velocity, and time step of the simulation.
- **User Interaction**: The robot waits for user input to either move to a target position or exit the program.
- **Simulation**: During movement, the robot's position is updated and displayed at each time step until the target is reached.

## Features

- **No External Dependencies**: Uses only standard C/C++ libraries.
- **Terminal-Based UI**: All interactions are done via the terminal.
- **Customizable Parameters**: Users can specify initial conditions and simulation parameters.

## How to Run the Program (linux)


1. **Compile the Program**:
   Before compiling, ensure that you have CMake installed on your system. Follow these steps to compile the program:
    ```bash
    # Create a build directory
    mkdir -p build
    cd build
    # Generate makefiles with CMake
    cmake ..
    # Compile the program
    make
    ```
   This will generate the executable in the `build` directory.
2. **Testing Framework**
The project uses Google Test, a widely used C++ testing framework, to ensure the functionality of the `Robot` class and associated methods. The tests cover initialization, position updates, and trajectory calculations to verify that the robot behaves as expected under various conditions.

### How to Run the Tests

since the project has Google Test submodlues libraries to run the tests you dont need to install it, Here's how you can compile and run the tests:

1. **Compile the Tests**:
   Navigate to your build directory and run CMake with the test option enabled:
   ```bash
   # Assuming you have already compiled the cmake project
   ctest
   ```
## Code Structure

- `main.cpp`: Handles user interactions and simulation loop.
- `Robot.cpp`: Defines the robot's behaviors and simulation mechanics.
- `Vec3.cpp`: Implements a simple 3D vector class used for vector based calculations.
- `test_robot.cpp`:implemented Google tests to make sure 
the functions and classes work as expected

## Future Enhancements

- **3D Visualization**: Implement a graphical interface to visualize the robot's movement.
- **Error Handling**: Improve error messages and handle unexpected inputs gracefully.
- **Performance Optimization**: Optimize the simulation for larger time steps and higher velocities.
