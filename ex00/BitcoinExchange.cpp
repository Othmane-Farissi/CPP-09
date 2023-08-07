#include    "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() {
       std::ifstream dBase("data.csv");
       std::string str;
       std::getline(dBase, str);
       while (std::getline(dBase, str))
       {
            size_t delPos = str.find(',');
            if (delPos == std::string::npos)
                throw std::runtime_error("Error: can't get delimiter pos");
		
        std::string date = str.substr(0, delPos);
		std::string tmp = str.substr(delPos + 1);
        double rate;
        std::istringstream rss(tmp);
        if (!(rss >> rate))
        {
            throw std::runtime_error("Error: can't get rate value");
        }

        bitDb[date] = rate;
       }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {
    bitDb = src.bitDb;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src) {
    if (this == &src) {
        return *this;
    }
    bitDb = src.bitDb;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

double    BitcoinExchange::getValue(std::string & date)
{
	std::map<std::string, double>::iterator it = bitDb.lower_bound(date);
	if (it != bitDb.end()) {
		return it->second;
	} else if (!bitDb.empty()) {
		return (--it)->second;
	}

	return -1.0;
}


bool    checkDate(std::string &date) {
    size_t posOne = date.find('-');
    size_t posTwo = date.find('-', posOne + 1);

    if (posOne == std::string::npos || posOne == posTwo)
        return false;
    std::string s1 = date.substr(0, posOne);
    std::string s2 = date.substr(posOne + 1, posTwo - posOne - 1); 
    std::string s3 = date.substr(posTwo + 1);

    int y, m, d;
    std::istringstream yStr(s1), mStr(s2), dStr(s3), other;
    if (s1.size() != 4)
        return false;
    if (!(yStr >> y) || !(mStr >>m) || !(dStr >> d) || !yStr.eof()|| !mStr.eof()|| !dStr.eof())
        return false;
    if (y < 2009 || m < 1 || m > 12 || d < 1 || d > 31)
		return false;

	if (m == 4 || m == 6 || m == 9 || m == 11) {
		if (d > 30)
			return false;
  
    }
    bool leap_y = ((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0);
          if (m == 2) {
            if (leap_y)
            {
                if (d > 29)
                    return false;
            }
            else
                if (d > 28)
                    return false;
        }
	return true;
}

bool    checkValue(double &val) {
    if (val < 0 || val > 1000) {
		return false;
	}
	return true;
}

