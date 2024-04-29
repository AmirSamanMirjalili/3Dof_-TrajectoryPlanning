#include <iostream>
#include "Robot.h"
#include <sstream>

int main() {
    double x, y, z, timeStep;
    int maxVelocity;
    std::string input;

    // Initial setup for initial position
    std::cout << "Enter initial position (x y z): (sample input: 0 0 0) ";
    std::getline(std::cin, input);
    std::istringstream iss(input);
    if (!(iss >> x >> y >> z)) {
        std::cerr << "Invalid initial position input. Please enter three numbers." << std::endl;
        return 1; // Exit with error code
    }
    Vec3 initialPosition(x, y, z);

    // Input for maximum velocity
    std::cout << "Enter maximum velocity: ";
    std::getline(std::cin, input);
    iss.clear(); // Clear any errors and the EOF flag on iss
    iss.str(input); // Use the new input
    if (!(iss >> maxVelocity)) {
        std::cerr << "Invalid input for maximum velocity. Please enter an integer." << std::endl;
        return 1; // Exit with error code
    }

    // Input for time step
    std::cout << "Enter time step for the simulation: ";
    std::getline(std::cin, input);
    iss.clear(); // Clear any errors and the EOF flag on iss
    iss.str(input); // Use the new input
    if (!(iss >> timeStep)) {
        std::cerr << "Invalid input for time step. Please enter a number." << std::endl;
        return 1; // Exit with error code
    }

    Robot robot(initialPosition, maxVelocity, timeStep, TrajectoryType::Line);

    // Loop for entering target positions
    while (true) {
        std::cout << "Enter target position (x y z) or type 'exit' to quit: (sample input: 10 20 3) ";
        std::getline(std::cin, input);
        if (input == "exit") {
            break;
        }
        iss.clear(); // Clear any errors and the EOF flag on iss
        iss.str(input); // Use the new input
        if (!(iss >> x >> y >> z)) {
            std::cout << "Invalid input. Please enter three numbers." << std::endl;
            continue;
        }
        Vec3 targetPosition(x, y, z);
        robot.setTargetPosition(targetPosition);

        robot.updatePosition();
        robot.accuracyCheck();

        std::cout << "Robot has reached the target position." << std::endl;
    }

    std::cout << "Exiting program." << std::endl;
    return 0;
}