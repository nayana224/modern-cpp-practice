#include <functional>
#include <iostream>
#include <string>

class Service
{
public:
    void setCallback(std::function<void()> callback)
    {
        callback_ = callback;
    }

    void request()
    {
        std::cout << "service request received\n";

        if (callback_) {
            callback_();
        }
    }

private:
    std::function<void()> callback_;
};

class MotionNode
{
public:
    MotionNode()
    : state_("IDLE")
    {
        service_.setCallback(
            [this]()
            {
                handleHome();
            }
        );
    }

    void requestHome()
    {
        service_.request();
    }


private:

    void handleHome()
    {
        state_ = "GO_HOME";

        std::cout << "state: "
                  << state_
                  << '\n';
        
        state_ = "IDLE";
    }

    Service service_;
    std::string state_;
};

int main(void) 
{
    MotionNode node;
    
    node.requestHome();

    return 0;
}
