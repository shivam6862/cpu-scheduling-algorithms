#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include "PrioritySchedulingAlgorithms.h"

PrioritySchedulingAlgorithms::PrioritySchedulingAlgorithms(std::vector<int> &arrivalTime, std::vector<int> &burstTime, std::vector<int> &priority)
{
    this->arrivalTime = arrivalTime;
    this->burstTime = burstTime;
    this->priority = priority;
    this->numberOfProcesses = arrivalTime.size();
    this->totalWaitingTime = 0;
    this->totalTurnAroundTime = 0;
}

void PrioritySchedulingAlgorithms::findCompletionTime()
{
    completionTime.resize(numberOfProcesses);
    waitingTime.resize(numberOfProcesses);
    turnAroundTime.resize(numberOfProcesses);
    responseTime.resize(numberOfProcesses);

    std::vector<bool> processed(numberOfProcesses, false);
    std::vector<int> remainingTime(numberOfProcesses);
    int currentTime = 0;
    int completedProcesses = 0;
    remainingTime = burstTime;

    while (completedProcesses < numberOfProcesses)
    {
        int currentProcess = -1;
        int highestPriority = -1;

        for (int i = 0; i < numberOfProcesses; i++)
        {
            if (arrivalTime[i] <= currentTime && !processed[i])
            {
                if (priority[i] > highestPriority)
                {
                    highestPriority = priority[i];
                    currentProcess = i;
                }

                if (priority[i] == highestPriority)
                {
                    if (arrivalTime[i] < arrivalTime[currentProcess])
                    {
                        currentProcess = i;
                    }
                }
            }
        }

        if (currentProcess == -1)
        {
            currentTime++;
            continue;
        }

        if (responseTime[currentProcess] == -1)
        {
            responseTime[currentProcess] = currentTime - arrivalTime[currentProcess];
        }

        remainingTime[currentProcess]--;

        if (remainingTime[currentProcess] == 0)
        {
            completionTime[currentProcess] = currentTime + 1;
            turnAroundTime[currentProcess] = completionTime[currentProcess] - arrivalTime[currentProcess];
            waitingTime[currentProcess] = turnAroundTime[currentProcess] - burstTime[currentProcess];
            totalWaitingTime += waitingTime[currentProcess];
            totalTurnAroundTime += turnAroundTime[currentProcess];
            processed[currentProcess] = true;
            completedProcesses++;
        }

        currentTime++;
    }
}

void PrioritySchedulingAlgorithms::findAverageTime()
{
    for (int i = 0; i < numberOfProcesses; i++)
    {
        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];
    }
}

void PrioritySchedulingAlgorithms::printTable()
{
    std::cout << "\nPriority Scheduling Algorithm\n";
    std::cout << std::left << std::setw(10) << "Process"
              << std::setw(11) << "Priority"
              << std::setw(15) << "Arrival Time"
              << std::setw(13) << "Burst Time"
              << std::setw(18) << "Completion Time"
              << std::setw(15) << "Waiting Time"
              << std::setw(18) << "Turnaround Time"
              << std::setw(16) << "Response Time" << std::endl;

    for (int i = 0; i < numberOfProcesses; i++)
    {
        std::cout << std::left << std::setw(10) << i + 1
                  << std::setw(11) << priority[i]
                  << std::setw(15) << arrivalTime[i]
                  << std::setw(13) << burstTime[i]
                  << std::setw(18) << completionTime[i]
                  << std::setw(15) << waitingTime[i]
                  << std::setw(18) << turnAroundTime[i]
                  << std::setw(16) << responseTime[i] << std::endl;
    }

    std::cout << "Average Waiting Time: " << std::fixed << std::setprecision(2) << (float)totalWaitingTime / numberOfProcesses << std::endl;
    std::cout << "Average Turnaround Time: " << std::fixed << std::setprecision(2) << (float)totalTurnAroundTime / numberOfProcesses << std::endl;
}

PrioritySchedulingAlgorithms::~PrioritySchedulingAlgorithms()
{
    std::cout << "Priority Scheduling Algorithm object is destroyed\n";
}