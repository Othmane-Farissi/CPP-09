#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
#include <string.h>

class BitcoinExchange {
    private :
            std::map<std::string, double> bitDb;
    public  :
            BitcoinExchange();
            BitcoinExchange(const BitcoinExchange& src);
            BitcoinExchange& operator=(const BitcoinExchange& src);
            ~BitcoinExchange();

            double getValue(std::string & date);
};

bool    checkDate(std::string &date);
bool    checkValue(double &val);