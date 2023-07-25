#pragma once

#include <iostream>
#include <stack>

class RPN
{
    private:
            std::string str;
            std::stack<char> storage;
    public:
            RPN(std::string& str);
            RPN(const RPN& src);
            RPN& operator=(const RPN& src);
            ~RPN();

            void    checker(std::string &str);
            int     converter(std::string &str); 

};