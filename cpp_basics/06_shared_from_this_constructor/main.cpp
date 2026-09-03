#include <iostream>
#include <memory>

class RobotNode
: public std::enable_shared_from_this<RobotNode>
{
public:
    RobotNode()
    {
        std::cout << "constructor\n";
    }

    void initialize()
    {
        std::cout << "initialize start\n";

        auto self = shared_from_this();

        std::cout << "use count: "
                  << self.use_count()
                  << '\n';
        
        std::cout << "initialized end\n";
    }
};

int main(void)
{
    auto node = std::make_shared<RobotNode>();

    std::cout << "after construction\n";

    node->initialize();

    return 0;
}