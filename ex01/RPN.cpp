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

static int operation(std::stack<std::string>& storage, char op) {

    if (storage.size() < 2) 
        throw std::runtime_error("Insufficient operands for the operation");
    std::string second = storage.top();
    storage.pop();
    std::string first = storage.top();
    storage.pop();
    if (op == '+')
        return strToInt(first) + strToInt(second);
    if (op == '-')
        return strToInt(first) - strToInt(second);
    if (op == '*')
        return strToInt(first) * (strToInt(second));
    if (op == '/') {
        if (strToInt(first) != 0)
            return strToInt(first) / strToInt(second);
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

    if (!is_operator(str[str.size() - 1]) || is_operator(str[0]) || is_operator(str[1]))
        throw std::runtime_error("syntax error");
    for (size_t i = 0; i < str.size(); i++) {
        if ((!isdigit(str[i]) && !is_operator(str[i])))
            throw std::runtime_error("syntax error");
    }
}

void RPN::converter(std::string& str) {
    checker(str);
    std::string rslt;

    for (size_t i = 0; i < str.size(); ++i) {
        char c = str[i];

        if (std::isdigit(c)) {
            storage.push(std::string(1, c));
        }
        else {
            rslt = intToStr(operation(storage, c));
            if (i != str.size() - 1)
                storage.push(rslt);
        }
    }
    
    if (!storage.empty())
        throw std::runtime_error("Insufficient operands for the operation");

    std::cout << rslt << std::endl;
}

