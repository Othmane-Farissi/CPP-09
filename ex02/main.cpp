#include "PmergeMe.hpp"
#include <sstream>
#include <vector>

// print the same sorted sequence in Before and after
// error print all the sequence
// add orthodox canonical form to the class
// check other's implementation



int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe <positive_integer_sequence>\n";
        return 1;
    }

    std::vector<int> values;
    for (int i = 1; i < argc; ++i) {
        std::istringstream iss(argv[i]);
        int num;
        if (!(iss >> num) || num <= 0) {
            std::cerr << "Error: Invalid input\n";
            return 1;
        }
        values.push_back(num);
    }

    PmergeMe pmerge;
    pmerge.parseAndSort(values);

    return 0;
}
