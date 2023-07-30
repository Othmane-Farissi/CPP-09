#include    "RPN.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
        {
            std::cout << "wrong count of arg " << std::endl;
            return 1;
        }
        std::string toConv = av[1];

        RPN rpn(toConv);
        rpn.converter(toConv);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
