#include <iostream>

int main(void)
{
    int value = 10;

    auto by_value = [value]()
    {
        std::cout << "by value: "
                  << value
                  << '\n';
    };

    auto by_reference = [&value]()
    {
        std::cout << "by reference: "
                  << value
                  << '\n';
    };

    value = 20;

    by_value();
    by_reference();

    return 0;
}