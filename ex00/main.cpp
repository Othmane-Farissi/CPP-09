#include    "BitcoinExchange.hpp"

void  rateCalculator(std::string& date, double value, BitcoinExchange& db) {

    double rate = db.getValue(date);
    if (rate == -1.0)
    {
		throw std::runtime_error("Error: No exchange rate available for this date");
    }
	
    std::cout << date << " => "
		  << value << " = " << value * rate
		  << std::endl;
}

void    parceLine(char *path)
{
    BitcoinExchange db;

    std::ifstream infile(path);
    if (!infile) {
        throw std::runtime_error("Error: could not open file.");
    }
    
    std::string line;
    std::getline(infile, line);
    while (std::getline(infile, line))
    {
        try
        {
        std::istringstream ss(line);
        std::string date;
        double val;
        char del;
        char other;

        if (!(ss >> date >> del >> val)) {
            throw std::runtime_error("Error: can't parce line");
        }
        if (ss >> other) {
            throw std::runtime_error("Error: bad input");
        }
        if (del != '|') {
            throw std::runtime_error("Error: Expected delimiter");
        }
        if (!checkDate(date)) {
            throw std::runtime_error("Error: bad input ");
        }
        if (!checkValue(val)) {
            throw std::runtime_error("Error: invalid value");
        }
        rateCalculator(date, val, db);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}
int main(int ac, char* av[]) {
   try {
        if (ac != 2) {
            throw std::runtime_error("Usage: ./btc  (input file) ");
        }
            parceLine(av[1]);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
