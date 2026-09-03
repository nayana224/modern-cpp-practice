#include <iostream>
#include <memory>
#include <string>

class Robot
: public std::enable_shared_from_this<Robot> // 중요
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

    std::shared_ptr<Robot> getSelf()
    {
        // 현재 객체 자신을 가리키는 shared_ptr을 얻는다.
        return shared_from_this();
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

    std::cout << "count1: " 
              << robot1.use_count()
              << '\n';

    auto robot2 = robot1->getSelf(); 

    std::cout << "count2: "
              << robot1.use_count()
              << '\n';

    robot2->printName();

    return 0;
}