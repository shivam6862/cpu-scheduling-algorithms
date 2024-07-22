#include <iostream>
#include <string>
#include <vector>
#include "PrioritySchedulingAlgorithms.h"

int main()
{
    std::vector<int> arrivalTime = {0, 1, 2, 4};
    std::vector<int> burstTime = {5, 4, 2, 1};
    std::vector<int> priority = {10, 20, 30, 40};

    PrioritySchedulingAlgorithms psa(arrivalTime, burstTime, priority);

    psa.findCompletionTime();
    psa.printTable();

    return 0;
}

// cd 4.PrioritySchedulingAlgorithms
// g++ main.cpp PrioritySchedulingAlgorithms.cpp -o output
// ./output
