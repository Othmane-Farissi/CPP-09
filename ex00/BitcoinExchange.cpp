#include    "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() {
       std::ifstream dBase("data.csv")
       std::string str;
       std::getline(file, str);
       while (std::getline(file, str))
       {
            size_t delPos = str.find(',');
            if (delPos == std::string::npos)
            {
                std::cerr << "Error: Invalid format" << '\n';
			    continue;
            }
		
        std::string date = str.substr(0, del);
		std::string tmp = str.substr(del + 1);

        double rate;
        std::istringstream rss(tmp);
        if (!(rss >> rate))
        {
            std::cerr << "Error: Invalid rate format" << '\n';
			continue;
        }

        bitdb[date] = rate;
       }
}

double    BitcoinExchange::getValue(std::string & date)
{
	std::map<std::string, double>::iterator it = bitDb.lower_bound(date);
	if (it != bitDB.end()) {
		return it->second;
	} else if (!bitDb.empty()) {
		return (--it)->second;
	}

	return -1.0;
}



bool    checkDate(std::string &date) {
    size_t posOne = data.find('-');
    size_t posTwo = data.find('-', poseOne);

    if (posOne == posTwo || posOne == std::string::npos)
        return false;
    
    std::string s1 = data.substr(0, posOne);
    std::string s2 = data.substr(posOne + 1, posTwo - posOne - 1); 
    std::string s3 = data.substr(posTwo + 1);
    int y, m, d;
    std::istringstream yStr(s1), mStr(s2), dStr(s3);
    if (!(yStr >> y) || !(mStr >> m) || !(dStr >> d))
        return false;
    if (y < 0 || m < 1 || m > 12 || d < 1 || d > 31)
		return false;

	if (m == 4 || m == 6 || m == 9 || m == 11) {
		if (d > 30)
			return false;
	return true;
}

bool    checkValue(double &val) {
    if (val < 0 || val > 1000) {
		std::cerr << "Error: Value "
			  << val
			  << " is not a positive number between 0 and 1000.\n";
		return false;
	}
	return true;

}

