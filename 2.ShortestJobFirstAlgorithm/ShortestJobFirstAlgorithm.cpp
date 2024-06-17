#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "ShortestJobFirstAlgorithm.h"

ShortestJobFirstAlgorithm::ShortestJobFirstAlgorithm(std::vector<int> &arrivalTime, std::vector<int> &burstTime)
{
    this->arrivalTime = arrivalTime;
    this->burstTime = burstTime;
    this->numberOfProcesses = arrivalTime.size();
    this->totalWaitingTime = 0;
    this->totalTurnAroundTime = 0;
}

void ShortestJobFirstAlgorithm::findCompletionTime()
{
    completionTime.resize(numberOfProcesses);
    waitingTime.resize(numberOfProcesses);
    turnAroundTime.resize(numberOfProcesses);
    responseTime.resize(numberOfProcesses);

    std::vector<bool> isCompleted(numberOfProcesses, false);
    int currentTime = 0;
    int completedProcesses = 0;

    while (completedProcesses < numberOfProcesses)
    {
        int shortestJobIndex = -1;
        int shortestJobBurstTime = 1e9;

        for (int i = 0; i < numberOfProcesses; i++)
        {
            if (!isCompleted[i] && arrivalTime[i] <= currentTime && burstTime[i] < shortestJobBurstTime)
            {
                shortestJobIndex = i;
                shortestJobBurstTime = burstTime[i];
            }
        }

        if (shortestJobIndex == -1)
        {
            currentTime++;
            continue;
        }

        completionTime[shortestJobIndex] = currentTime + burstTime[shortestJobIndex];
        currentTime = completionTime[shortestJobIndex];
        waitingTime[shortestJobIndex] = currentTime - arrivalTime[shortestJobIndex] - burstTime[shortestJobIndex];
        turnAroundTime[shortestJobIndex] = waitingTime[shortestJobIndex] + burstTime[shortestJobIndex];
        responseTime[shortestJobIndex] = waitingTime[shortestJobIndex];
        totalWaitingTime += waitingTime[shortestJobIndex];
        totalTurnAroundTime += turnAroundTime[shortestJobIndex];
        isCompleted[shortestJobIndex] = true;
        completedProcesses++;
    }
}

void ShortestJobFirstAlgorithm::findAverageTime()
{
    for (int i = 0; i < numberOfProcesses; i++)
    {
        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];
    }
}

void ShortestJobFirstAlgorithm::printTable()
{
    std::cout << "\nShortest Job First Algorithm\n";
    std::cout << std::setw(10) << "Process"
              << std::setw(15) << "Arrival Time"
              << std::setw(13) << "Burst Time"
              << std::setw(18) << "Completion Time"
              << std::setw(15) << "Waiting Time"
              << std::setw(18) << "Turnaround Time"
              << std::setw(16) << "Response Time"
              << std::endl;

    for (int i = 0; i < numberOfProcesses; i++)
    {
        std::cout << std::setw(10) << i + 1
                  << std::setw(15) << arrivalTime[i]
                  << std::setw(13) << burstTime[i]
                  << std::setw(18) << completionTime[i]
                  << std::setw(15) << waitingTime[i]
                  << std::setw(18) << turnAroundTime[i]
                  << std::setw(16) << responseTime[i]
                  << std::endl;
    }

    std::cout << "\nAverage Waiting Time: " << (float)totalWaitingTime / numberOfProcesses;
    std::cout << "\nAverage Turnaround Time: " << (float)totalTurnAroundTime / numberOfProcesses;
    std::cout << std::endl;
}

ShortestJobFirstAlgorithm::~ShortestJobFirstAlgorithm()
{
}