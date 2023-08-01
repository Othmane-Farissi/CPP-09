#pragma once

#include <iostream>
#include <vector>
#include <list>

class PmergeMe {
public:
    PmergeMe();

    void parseAndSort(const std::vector<int>& values);

    void displayResults() const;

    void displayListContent(const std::list<int>& container) const ;
    void displayVectorContent(const std::vector<int>& container) const; 
private:
    std::vector<int> vecContainer;
    std::list<int> listContainer;

    void mergeInsertSort(std::vector<int>& container);
    void mergeInsertSort(std::list<int>& container);
};
