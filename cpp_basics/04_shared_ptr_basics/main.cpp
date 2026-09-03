#include <iostream>
#include <memory>
#include <string>

class Robot
{
public:
    Robot(const std::string & name)
    : name_(name)
    {
        std::cout << "created: " << name_ << '\n';
    }

    ~Robot()
    {
        std::cout << "destroyed: " << name_ << '\n';
    }

    void printName() const
    {
        std::cout << "robot: " << name_ << '\n';
    }

private:
    std::string name_;
};

int main(void)
{
    auto robot1 = std::make_shared<Robot>("UR10e");

    std::cout << "count: "
              << robot1.use_count() // 1
              << '\n';

    {
        std::shared_ptr<Robot> robot2 = robot1;

        std::cout << "count: "
              << robot1.use_count() // 2
              << '\n';
    }

    std::cout << "count: "
              << robot1.use_count() // 1
              << '\n';

    return 0;
}