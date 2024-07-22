#include <iostream>
#include <string>
#include <vector>
#include "ShortestJobFirstAlgorithm.h"

int main()
{
    std::vector<int> arrivalTime = {1, 2, 1, 4};
    std::vector<int> burstTime = {3, 4, 2, 4};

    ShortestJobFirstAlgorithm sjf(arrivalTime, burstTime);

    sjf.findCompletionTime();
    sjf.printTable();

    return 0;
}

// cd 2.ShortestJobFirstAlgorithm
// g++ main.cpp ShortestJobFirstAlgorithm.cpp -o output
// ./output