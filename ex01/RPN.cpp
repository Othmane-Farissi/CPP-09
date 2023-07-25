#include    "RPN.hpp"

RPN::RPN(std::string& str) : str(str) {}

RPN::RPN(const RPN& src) : str(src.str) {}

RPN& RPN::operator=(const RPN& src) {
    if (this != src)
    {
        str = src.str;
    }
    return *this;
}

RPN::~RPN() {}

static int strToInt(const std::string& strNumber) {
    int number;
    std::istringstream iss(strNumber);

    if (!(iss >> number)) {
          throw std::runtime_error("conversion failed");
    }    
    return number;
}

static std::string intToStr(int number) {
    std::stringstream ss;
    ss << number;
    return ss.str();
}

static int operation(std::stack<char> storage, char& op, int& count)
{
    std::string first;
    std::string second;
    
    for (;count > 1; count--)
    {
        first += static_cast<std::string>(storage.pop());
    }
    second = static_cast<std::string>(storage.pop())
    if (op == '+')
        return (strToInt(first) + strToInt(second));
    if (op == '-')
        return (strToInt(first) - strToInt(second));
    if (op == '/')
    {
        if (strToInt(second) != 0)
            return (strToInt(first) / strToInt(second));
        throw std::runtime_error("You cannot divide by 0");
    }
    return (strToInt(first) * strToInt(second));
}

static bool is_operator(char& c)
{
    if (c != '+' && c != '-' && c != '/' && c != '*')
        return false;
    return true;
}

void    RPN::checker(std::string& str)
{
    if (!is_operator(str[str.size() - 1]) || is_operator(str[0]))
        throw std::runtime_error("syntax error");
    for (int i = 0; i < (str.size() - 1); i++)
    {
        if (!isdigit(str[i]) && !is_operator(str[i]))
            throw std::runtime_error("syntax_error");
    }
}

void    RPN::converter(std::string& str)
{
    checker(str);
    std::string rslt;
    int count = 0;

    for (int i = 0; i < (str.size() - 1); i++)
    {
        if (isdigit(str[i]))
        {
            storage.push(str[i]);
            count++;
        }
        else
            rslt = operation(storage, str[i], count);
            stack.push();
            // storage need to be an in stack
    }
}