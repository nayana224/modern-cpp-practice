#include <iostream>

int add(int a, int b)
{
    return a + b;
}

int main(void)
{
    const int result1 = add(3, 4);

    auto add_lambda = [](int a, int b)
    {
        return a + b;
    };

    const int result2 = add_lambda(3, 4);

    std::cout << "function: " << result1 << std::endl;
    std::cout << "lambda  : " << result2 << std::endl;

    return 0;
}