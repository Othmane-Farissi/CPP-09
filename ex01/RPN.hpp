#pragma once

#include <iostream>
#include <stack>

class RPN {
private:
    std::string str;
    std::stack<std::string> storage;

public:
    RPN(std::string& str);
    RPN(const RPN& src);
    RPN& operator=(const RPN& src);
    ~RPN();

    void checker(std::string& str);
    void converter(std::string& str);
};
