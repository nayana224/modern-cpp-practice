#pragma once

#include <string>

class RobotMotion
{
public:
    RobotMotion(const std::string & name);

    bool goHome();
    void printState() const;
    
private:
    std::string name_;
    std::string current_state_;
};