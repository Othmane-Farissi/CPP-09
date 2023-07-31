#pragma once

#include <vector>
#include <list>

class PmergeMe {
public:
    PmergeMe();

    void parseAndSort(const std::vector<int>& values);

    void displayResults() const;

private:
    std::vector<int> vecContainer;
    std::list<int> listContainer;

    void mergeInsertSort(std::vector<int>& container);
    void mergeInsertSort(std::list<int>& container);
};
