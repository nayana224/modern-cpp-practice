#include <iostream>
#include <functional>

void runCallback(const std::function<void()> & callback)
{
    std::cout << "callback requested\n";
    
    callback();
}

class Robot
{
public: 
    Robot(const std::string & name)
    : name_(name)
    {
    }

    void registerAndrun()
    {
        runCallback(
            [this]()
            {
                handleHome();
            }
        );
    }

private:
    void handleHome()
    {
        std::cout << name_
                  << " -> GO_HOME\n";
    }
    
    std::string name_;
};


int main(void)
{
    Robot robot("UR10e");

    robot.registerAndrun();

    return 0;
}