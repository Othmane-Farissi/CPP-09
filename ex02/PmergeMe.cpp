// PmergeMe.cpp

#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <ctime>

PmergeMe::PmergeMe() {}


void PmergeMe::displayVectorContent(const std::vector<int>& container) const {
    for (std::vector<int>::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << " " << *it;
    }
}

void PmergeMe::displayListContent(const std::list<int>& container) const {
    for (std::list<int>::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << " " << *it;
    }
}


void PmergeMe::parseAndSort(const std::vector<int>& values) {
    vecContainer = values;
    listContainer.clear();
    listContainer.insert(listContainer.begin(), values.begin(), values.end());

    clock_t startVec = clock();
    mergeInsertSort(vecContainer);
    clock_t endVec = clock();

    clock_t startList = clock();
    mergeInsertSort(listContainer);
    clock_t endList = clock();

    std::cout << "Before:";
    displayVectorContent(vecContainer);
    std::cout << "\n";
    std::cout << "Before:";
    displayListContent(listContainer);
    std::cout << "\n";

    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC;
    double timeList = static_cast<double>(endList - startList) / CLOCKS_PER_SEC;

    std::cout << "After:";
    displayVectorContent(vecContainer);
    std::cout << "\n";
    std::cout << "After:";
    displayListContent(listContainer);
    std::cout << "\n";

    std::cout << "Time to process a range of " << values.size() << " elements with std::vector: " << timeVec << " seconds\n";
    std::cout << "Time to process a range of " << values.size() << " elements with std::list: " << timeList << " seconds\n";
}


void PmergeMe::displayResults() const {
    std::cout << "Before (Vector):";
    for (std::vector<int>::const_iterator it = vecContainer.begin(); it != vecContainer.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << "\n";

    std::cout << "Before (List):";
    for (std::list<int>::const_iterator it = listContainer.begin(); it != listContainer.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << "\n";
    std::cout << "After:";
    for (std::vector<int>::const_iterator it = vecContainer.begin(); it != vecContainer.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << "\n";
}

void PmergeMe::mergeInsertSort(std::vector<int>& container) {
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

void PmergeMe::mergeInsertSort(std::list<int>& container) {
    if (container.size() <= 1)
        return;

    // Split the list into two halves
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



