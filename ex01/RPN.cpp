#include "RPN.hpp"
#include <sstream>
#include <cstdlib>


RPN::RPN(std::string& str) : str(str) {}

RPN::RPN(const RPN& src) : str(src.str) {}

RPN& RPN::operator=(const RPN& src) {
    if (this != &src) {
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

static int operation(std::stack<std::string>& storage, char op, int& count) {
    if (count < 2) {
        throw std::runtime_error("Insufficient operands for the operation");
    }

    std::string second = storage.top();
    storage.pop();
    count--;
    std::string first;

    for (; count > 0; count--) {
        first = storage.top() + first;
        storage.pop();
    }
    if (op == '+')
        return strToInt(first) + strToInt(second);
    if (op == '-')
        return strToInt(first) - strToInt(second);
    if (op == '*')
    {
        
    // std::cout << "first: " << strToInt(first) << std::endl;
    // std::cout << "second: " << strToInt(second) << std::endl;
        return strToInt(first) * (strToInt(second));
    }
    if (op == '/') {
        if (strToInt(first) != 0)
            return strToInt(second) / strToInt(first);
        else
            throw std::runtime_error("You cannot divide by 0");
    }

    throw std::runtime_error("Invalid operator");
}


static bool is_operator(char c) {
    if (c != '+' && c != '-' && c != '/' && c != '*')
        return false;
    return true;
}

void RPN::checker(std::string& str) {
    if (!is_operator(str[str.size() - 1]) || is_operator(str[0]))
        throw std::runtime_error("syntax error");
    for (size_t i = 0; i < str.size(); i++) {
        if (!isdigit(str[i]) && !is_operator(str[i]))
            throw std::runtime_error("syntax error");
    }
}

void RPN::converter(std::string& str) {
    checker(str);
    int count = 0;
    std::string rslt;

    for (size_t i = 0; i < str.size(); ++i) {
        char c = str[i];
        if (std::isspace(c)) {
            continue;
        } else if (std::isdigit(c)) {
            storage.push(std::string(1, c)); 
        } else {
            rslt = intToStr(operation(storage, c, count));
            storage.push(rslt);
        }
        count++;
    }
    std::cout << rslt << std::endl;
}

