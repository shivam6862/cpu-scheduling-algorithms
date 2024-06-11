#include <iostream>
#include <string>
#include <vector>
#include "RoundRobinAlgorithm.h"

int main()
{
    std::vector<int> arrivalTime = {0, 1, 2, 4};
    std::vector<int> burstTime = {5, 4, 2, 1};
    int quantumTime = 2;

    RoundRobinAlgorithm rr(arrivalTime, burstTime, quantumTime);

    rr.findCompletionTime();
    rr.findAverageTime();
    rr.printTable();

    return 0;
}

// cd 3.RoundRobinAlgorithm
// g++ main.cpp RoundRobinAlgorithm.cpp -o output
// ./output
