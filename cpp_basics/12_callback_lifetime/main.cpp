#include <functional>
#include <iostream>

class Button
{
public: 
    void setCallback(const std::function<void()> & callback)
    {
        std::cout << "setCallback start\n";

        callback_ = callback;

        std::cout << "setCallback end\n";
    }

    void press()
    {
        std::cout << "press start\n";

        if (callback_) {
            callback_();
        }

        std::cout << "press end\n";
    }

private:
    std::function<void()> callback_;
};

int main(void)
{
    Button button;

    std::cout << "before setCallback\n";

    button.setCallback(
        []()
        {
            std::cout << "lambda executed\n";
        }
    );

    std::cout << "after setCallback\n";

    button.press();

    return 0;
}

/*
before setCallback
setCallback start
setCallback end
after setcallback
press start
lambda executed
press end
*/
