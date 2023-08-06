// pMergeMe.cpp

#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <ctime>

void    pMergeMe(std::vector<int> &vecVal,std::list<int> &lstVal) {
    std::vector<int> vecContainer;
    std::list<int> listContainer;

    vecContainer = vecVal;
    listContainer = lstVal;

    printBefore(vecContainer);

    clock_t startVec = clock();
    mergeInsertSort(vecContainer);
    clock_t endVec = clock();

    clock_t startList = clock();
    mergeInsertSort(listContainer);
    clock_t endList = clock();

    printAfter(vecContainer);

    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000; // Convert to microseconds
    double timeList = static_cast<double>(endList - startList) / CLOCKS_PER_SEC * 1000000; // Convert to microseconds

    std::cout << "Time to process a range of " << vecContainer.size() << " elements with std::vector: " << timeVec << " us\n";
    std::cout << "Time to process a range of " << listContainer.size() << " elements with std::list: " << timeList << " us\n";
}

void printBefore(const std::vector<int>& container) {
    std::cout << "Before :";
    for (std::vector<int>::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << "\n";
}


void printAfter(const std::vector<int>& container) {
    std::cout << "After:";
    for (std::vector<int>::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << "\n";
}

void mergeInsertSort(std::vector<int>& container) {
    if (container.size() <= 1)
        return;

    std::vector<int>::size_type mid = container.size() / 2;
    std::vector<int> left(container.begin(), container.begin() + mid);
    std::vector<int> right(container.begin() + mid, container.end());

    mergeInsertSort(left);
    mergeInsertSort(right);

    container.clear();
    std::vector<int>::iterator leftIt = left.begin();
    std::vector<int>::iterator rightIt = right.begin();

    while (leftIt != left.end() && rightIt != right.end()) {
        if (*leftIt < *rightIt) {
            container.push_back(*leftIt);
            ++leftIt;
        } else {
            container.push_back(*rightIt);
            ++rightIt;
        }
    }

    while (leftIt != left.end()) {
        container.push_back(*leftIt);
        ++leftIt;
    }

    while (rightIt != right.end()) {
        container.push_back(*rightIt);
        ++rightIt;
    }
}

void mergeInsertSort(std::list<int>& container) {
    if (container.size() <= 1)
        return;

    std::list<int> left;
    std::list<int> right;
    bool addToLeft = true;

    for (std::list<int>::iterator it = container.begin(); it != container.end(); ++it) {
        if (addToLeft) {
            left.push_back(*it);
        } else {
            right.push_back(*it);
        }
        addToLeft = !addToLeft;
    }

    // Recursively sort the two halves
    mergeInsertSort(left);
    mergeInsertSort(right);

    // Merge the sorted halves
    container.clear();
    std::list<int>::iterator leftIt = left.begin();
    std::list<int>::iterator rightIt = right.begin();

    while (leftIt != left.end() && rightIt != right.end()) {
        if (*leftIt < *rightIt) {
            container.push_back(*leftIt);
            ++leftIt;
        } else {
            container.push_back(*rightIt);
            ++rightIt;
        }
    }

    while (leftIt != left.end()) {
        container.push_back(*leftIt);
        ++leftIt;
    }

    while (rightIt != right.end()) {
        container.push_back(*rightIt);
        ++rightIt;
    }
}



