#include    "BitcoinExchange.hpp"

void  rateCalculator(std::string& date, double value) {
    BitcoinExchange db();

    double rate = db.getValue(date);
    if (rate == -1.0)
    {
        std::cerr << "Error: No exchange rate available for date => "
			  << date << '\n';
			continue;
    }
	
    std::cout << date << " => "
		  << value << " = " << value * exchangeRate
		  << '\n';
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " input_file" << std::endl;
        return 1;
    }
    std::ifstream infile(argv[1]);
    if (!infile) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    std::string line;
    int i = 0;
    std::getline(infile, line)
    while (std::getline(infile, line))
    {
        std::istringstream ss(line);
		std::string date;
		double val;
		char del;

i       if (!(ss >> date >> del >> val)) {
			std::cerr << "Error: Unable to parse line" << '\n';
			continue;
		}

		if (del != '|') {
			std::cerr << "Error: Expected delimiter => "
				  << line << '\n';
			continue;
		}

		if (!checkDate(date)) {
			std::cerr << "Error: bad input => "
				  << line << '\n';
			continue;
		}

		if (!checkValue(val)) {
			continue;
		}
        rateCalculator(date, val);
    }
    return 0;
}
