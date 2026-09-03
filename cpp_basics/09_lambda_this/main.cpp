#include <iostream>
#include <string>

class Robot
{
public:
    Robot(const std::string & name)
    : name_(name)
    {
    }

    void run()
    {
        auto print_name = [this]()
        {
            std::cout << "robot: "
                      << name_
                      << '\n';
        };

        print_name();
    }

private:
    std::string name_;
};

int main(void)
{
    Robot robot("UR10e");

    robot.run();

    return 0;
}