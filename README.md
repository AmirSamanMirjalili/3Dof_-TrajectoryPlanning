# simple_3dof_object

# Simple 2D Robot Simulator

## Project Overview

This project simulates a simple 2D flying robot that translates in an environment with three degrees of freedom (3 DOF). The robot can move to a target position at a specified maximum velocity, assuming infinite acceleration and no system delays.

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
    bash
    # Create a build directory
    mkdir -p build
    cd build
    # Generate makefiles with CMake
    cmake ..
    # Compile the program
    make
