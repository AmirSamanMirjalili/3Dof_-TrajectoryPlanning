#include <iostream>
#include "Robot.h"

int main() {
    double x, y, z, timeStep;
    int maxVelocity;
    std::string input;

    // Initial setup
    std::cout << "Enter initial position (x y z): ";
    std::cin >> x >> y >> z;
    Vec3 initialPosition(x, y, z);

    std::cout << "Enter maximum velocity: ";
    std::cin >> maxVelocity;

    std::cout << "Enter time step for the simulation: ";
    std::cin >> timeStep;

    Robot robot(initialPosition, maxVelocity, timeStep);

    while (true) {
        std::cout << "Enter target position (x y z) or type 'exit' to quit: ";
        std::cin >> input;
        if (input == "exit") {
            break;
        } else {
            std::cin.putback(input[0]); // Put the first character back into the stream
            std::cin >> x >> y >> z; // Read the target position
            Vec3 targetPosition(x, y, z);
            robot.setTargetPosition(targetPosition);

            // Simulation loop
            while (!robot.isAtTarget()) {
                robot.updatePosition();
                robot.printPosition();
            }

            std::cout << "Robot has reached the target position." << std::endl;
        }
    }

    std::cout << "Exiting program." << std::endl;
    return 0;
}