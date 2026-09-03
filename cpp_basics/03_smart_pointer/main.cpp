#include <iostream>
#include <memory>
#include <string>

class RobotMotion
{
public:
    RobotMotion(const std::string & name)
    : name_(name)
    {
        std::cout << "created: " << name_ << '\n';
    }

    ~RobotMotion() 
    {
        std::cout << "destroyed: " << name_ << '\n';
    }

    void goHome()
    {
        std::cout << name_ << " -> GO_HOME\n";
    }

private:
    std::string name_;
};

int main(void)
{
    std::unique_ptr<RobotMotion> motion;

    std::cout << "before creation\n";

    motion = std::make_unique<RobotMotion>("UR10e");

    std::cout << "after creataion\n";

    motion->goHome();

    return 0;
}