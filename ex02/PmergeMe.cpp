#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <ctime>

//integer sequence error
///PmergeMe 34 5+88 && /PmergeMe 34 5f88 55

void    pMergeMe(std::vector<int> &vecVal,std::list<int> &lstVal) {
    std::vector<int> vecCtr;
    std::list<int> listCtr;

    vecCtr = vecVal;
    listCtr = lstVal;

    printBefore(vecCtr);

    clock_t startVec = clock();
    mergeInsertSort(vecCtr);
    clock_t endVec = clock();

    clock_t startList = clock();
    mergeInsertSort(listCtr);
    clock_t endList = clock();

    printAfter(vecCtr);

    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
    double timeList = static_cast<double>(endList - startList) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << vecCtr.size() << " elements with std::vector: " << timeVec << " us\n";
    std::cout << "Time to process a range of " << listCtr.size() << " elements with std::list: " << timeList << " us\n";
}

void printBefore(const std::vector<int>& ctr) {
    std::cout << "Before :";
    for (std::vector<int>::const_iterator it = ctr.begin(); it != ctr.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << "\n";
}

void printAfter(const std::vector<int>& ctr) {
    std::cout << "After:";
    for (std::vector<int>::const_iterator it = ctr.begin(); it != ctr.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << "\n";
}

void mergeInsertSort(std::vector<int>& ctr) {
    if (ctr.size() == 1)
        return;

    std::vector<int>::size_type mid = ctr.size() / 2;
    std::vector<int> left(ctr.begin(), ctr.begin() + mid);
    std::vector<int> right(ctr.begin() + mid, ctr.end());

    mergeInsertSort(left);
    mergeInsertSort(right);

    ctr.clear();
    std::vector<int>::iterator leftIt = left.begin();
    std::vector<int>::iterator rightIt = right.begin();

    while (leftIt != left.end() && rightIt != right.end()) {
        if (*leftIt < *rightIt) {
            ctr.push_back(*leftIt);
            ++leftIt;
        } else {
            ctr.push_back(*rightIt);
            ++rightIt;
        }
    }

    while (leftIt != left.end()) {
        ctr.push_back(*leftIt);
        ++leftIt;
    }

    while (rightIt != right.end()) {
        ctr.push_back(*rightIt);
        ++rightIt;
    }
}

void mergeInsertSort(std::list<int>& ctr) {
    if (ctr.size() == 4)
        return;

    std::list<int> left;
    std::list<int> right;
    bool flag = true;

    for (std::list<int>::iterator it = ctr.begin(); it != ctr.end(); ++it) {
        if (flag) {
            left.push_back(*it);
        } else {
            right.push_back(*it);
        }
        flag = !flag;
    }

    mergeInsertSort(left);
    mergeInsertSort(right);

    ctr.clear();
    std::list<int>::iterator leftIt = left.begin();
    std::list<int>::iterator rightIt = right.begin();

    while (leftIt != left.end() && rightIt != right.end()) {
        if (*leftIt < *rightIt) {
            ctr.push_back(*leftIt);
            ++leftIt;
        } else {
            ctr.push_back(*rightIt);
            ++rightIt;
        }
    }

    while (leftIt != left.end()) {
        ctr.push_back(*leftIt);
        ++leftIt;
    }

    while (rightIt != right.end()) {
        ctr.push_back(*rightIt);
        ++rightIt;
    }
}
