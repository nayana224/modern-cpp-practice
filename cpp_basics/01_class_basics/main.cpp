#include <iostream>
#include <string>

class RobotMotion
{
public:
    RobotMotion(const std::string & name)
    : name_(name), current_state_("IDLE")
    {
        std::cout << "RobotMotion created: " << name_ << '\n';
    }

    bool goHome()
    {
        current_state_ = "GO_HOME";

        std::cout << name_ 
                  << " -> "
                  << current_state_
                  << '\n';

        current_state_ = "IDLE";

        return true;
    }

    void printState() const
    {
        std::cout << "state: "
                  << current_state_
                  << '\n';
    }

private:
    std::string name_;
    std::string current_state_;
};

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