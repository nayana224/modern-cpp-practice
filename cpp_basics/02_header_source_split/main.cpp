#include "robot_motion.hpp"

#include <iostream>

int main(void)
{
    RobotMotion robot("UR10e");

    robot.printState();

    const bool success = robot.goHome();

    std::cout << "success: "
              << success
              << '\n';

    robot.printState();

    return 0;
}