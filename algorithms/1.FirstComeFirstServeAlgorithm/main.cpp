#include <iostream>
#include <string>
#include <vector>
#include "FirstComeFirstServe.h"

int main()
{
    std::vector<int> arrivalTime = {0, 1, 5, 6};
    std::vector<int> burstTime = {2, 2, 3, 4};

    FirstComeFirstServe fcfs(arrivalTime, burstTime);

    fcfs.findCompletionTime();
    fcfs.findWaitingTime();
    fcfs.findTurnAroundTime();
    fcfs.findResponseTime();
    fcfs.findAverageTime();
    fcfs.printTable();
    fcfs.printGanttChart();

    return 0;
}

// g++ main.cpp FirstComeFirstServe.cpp -o output
// ./output