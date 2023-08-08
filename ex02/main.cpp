#include "PmergeMe.hpp"
#include <sstream>
#include <vector>

int main(int argc, char* argv[]) {
   
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe <positive_integer_sequence>\n";
        return 1;
    }

    std::vector<int> vecVal;
    std::list<int> lstVal;
    for (int i = 1; i < argc; ++i) {
        std::istringstream iss(argv[i]);
        int num;
        if (!(iss >> num) || num <= 0) {
            std::cerr << "Error: Invalid input\n";
            return 1;
        }
        vecVal.push_back(num);
        lstVal.push_back(num);
    }

    pMergeMe(vecVal, lstVal);

    return 0;
}
