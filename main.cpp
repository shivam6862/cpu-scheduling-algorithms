#include <iostream>
#include <string>
#include <vector>
#include "1.FirstComeFirstServeAlgorithm/FirstComeFirstServe.h"
#include "2.ShortestJobFirstAlgorithm/ShortestJobFirstAlgorithm.h"
#include "3.RoundRobinAlgorithm/RoundRobinAlgorithm.h"
#include "4.PrioritySchedulingAlgorithms/PrioritySchedulingAlgorithms.h"

int main()
{
    std::vector<int> arrivalTime = {0, 1, 2, 3};
    std::vector<int> burstTime = {5, 3, 8, 6};

    FirstComeFirstServe fcfs(arrivalTime, burstTime);
    fcfs.findCompletionTime();
    fcfs.findWaitingTime();
    fcfs.findTurnAroundTime();
    fcfs.findResponseTime();
    fcfs.findAverageTime();
    fcfs.printTable();

    ShortestJobFirstAlgorithm sjf(arrivalTime, burstTime);
    sjf.findCompletionTime();
    sjf.findAverageTime();
    sjf.printTable();

    int quantumTime = 2;
    RoundRobinAlgorithm rr(arrivalTime, burstTime, quantumTime);
    rr.findCompletionTime();
    rr.findAverageTime();
    rr.printTable();

    std::vector<int> priority = {2, 1, 3, 2};
    PrioritySchedulingAlgorithms psa(arrivalTime, burstTime, priority);
    psa.findCompletionTime();
    psa.printTable();
    psa.findAverageTime();

    return 0;
}

// g++ main.cpp 1.FirstComeFirstServeAlgorithm/FirstComeFirstServe.cpp 2.ShortestJobFirstAlgorithm/ShortestJobFirstAlgorithm.cpp 3.RoundRobinAlgorithm/RoundRobinAlgorithm.cpp 4.PrioritySchedulingAlgorithms/PrioritySchedulingAlgorithms.cpp -o output && ./output
