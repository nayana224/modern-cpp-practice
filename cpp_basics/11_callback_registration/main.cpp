#include <functional>
#include <iostream>

class Button
{
public:
    void setCallback(const std::function<void()> & callback)
    {
        callback_ = callback;
    }

    void press()
    {
        std::cout << "button pressed\n";

        if (callback_) {
            callback_();
        }
    } 

private:
    std::function<void()> callback_;
};

int main(void)
{
    Button button;
    
    button.setCallback(
        []()
        {
            std::cout << "callback executed\n";
        }
    );

    std::cout << "callback registered\n";

    button.press();

    return 0;
}