#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "1.FirstComeFirstServeAlgorithm/FirstComeFirstServe.h"
#include "2.ShortestJobFirstAlgorithm/ShortestJobFirstAlgorithm.h"
#include "3.RoundRobinAlgorithm/RoundRobinAlgorithm.h"
#include "4.PrioritySchedulingAlgorithms/PrioritySchedulingAlgorithms.h"

int main()
{
    std::ifstream infile;
    infile.open("data.txt");

    if (!infile)
    {
        std::cerr << "Error: File not found!" << std::endl;
        return 1;
    }

    std::vector<int> arrivalTime;
    std::vector<int> burstTime;
    std::vector<int> priority;

    while (!infile.eof())
    {
        int a, b, p;
        infile >> a >> b >> p;
        arrivalTime.push_back(a);
        burstTime.push_back(b);
        priority.push_back(p);
    }

    FirstComeFirstServe fcfs(arrivalTime, burstTime);
    fcfs.findCompletionTime();
    fcfs.findWaitingTime();
    fcfs.findTurnAroundTime();
    fcfs.findResponseTime();
    fcfs.findAverageTime();
    fcfs.printTable();

    ShortestJobFirstAlgorithm sjf(arrivalTime, burstTime);
    sjf.findCompletionTime();
    sjf.printTable();

    int quantumTime = 2;
    RoundRobinAlgorithm rr(arrivalTime, burstTime, quantumTime);
    rr.findCompletionTime();
    rr.findAverageTime();
    rr.printTable();

    PrioritySchedulingAlgorithms psa(arrivalTime, burstTime, priority);
    psa.findCompletionTime();
    psa.printTable();

    return 0;
}

// g++ main.cpp 1.FirstComeFirstServeAlgorithm/FirstComeFirstServe.cpp 2.ShortestJobFirstAlgorithm/ShortestJobFirstAlgorithm.cpp 3.RoundRobinAlgorithm/RoundRobinAlgorithm.cpp 4.PrioritySchedulingAlgorithms/PrioritySchedulingAlgorithms.cpp -o output
// ./output
