#include "robot_motion.hpp"

#include <iostream>

RobotMotion::RobotMotion(const std::string & name)
: name_(name), current_state_("IDLE")
{
    std::cout << "RobotMotion created: " << name_ << '\n';
}

bool RobotMotion::goHome()
{
    current_state_ = "GO_HOME";

    std::cout << name_
              << " -> "
              << current_state_
              << '\n';

    current_state_ = "IDLE";

    return true;
}

void RobotMotion::printState() const
{
    std::cout << "state: "
              << current_state_
              << '\n';
}