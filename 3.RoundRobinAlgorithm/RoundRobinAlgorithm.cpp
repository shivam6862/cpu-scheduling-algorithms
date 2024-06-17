#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include "RoundRobinAlgorithm.h"

RoundRobinAlgorithm::RoundRobinAlgorithm(std::vector<int> &arrivalTime, std::vector<int> &burstTime, int quantumTime)
{
    this->arrivalTime = arrivalTime;
    this->burstTime = burstTime;
    this->numberOfProcesses = arrivalTime.size();
    this->totalWaitingTime = 0;
    this->totalTurnAroundTime = 0;
    this->quantumTime = quantumTime;
}

void RoundRobinAlgorithm::findCompletionTime()
{
    completionTime.resize(numberOfProcesses);
    waitingTime.resize(numberOfProcesses);
    turnAroundTime.resize(numberOfProcesses);
    responseTime.resize(numberOfProcesses);

    std::queue<int> q;
    std::vector<int> remainingTime(numberOfProcesses);
    std::vector<bool> processed(numberOfProcesses, false);
    std::vector<int> CPUFirstTime(numberOfProcesses, 0);
    int currentTime = 0;
    int completedProcesses = 0;
    remainingTime = burstTime;

    for (int i = 0; i < numberOfProcesses; i++)
    {
        if (arrivalTime[i] <= currentTime && !processed[i])
        {
            q.push(i);
            processed[i] = true;
        }
    }

    while (completedProcesses < numberOfProcesses)
    {
        if (q.empty())
        {
            for (int i = 0; i < numberOfProcesses; i++)
            {
                if (!processed[i])
                {
                    currentTime = arrivalTime[i];
                    q.push(i);
                    processed[i] = true;
                    break;
                }
            }
        }

        int currentProcess = q.front();
        q.pop();

        if (remainingTime[currentProcess] == burstTime[currentProcess])
        {
            CPUFirstTime[currentProcess] = currentTime;
        }

        if (remainingTime[currentProcess] <= quantumTime)
        {
            currentTime += remainingTime[currentProcess];
            completionTime[currentProcess] = currentTime;
            remainingTime[currentProcess] = 0;
            completedProcesses++;
        }
        else
        {
            currentTime += quantumTime;
            remainingTime[currentProcess] -= quantumTime;
        }

        for (int i = 0; i < numberOfProcesses; i++)
        {
            if (arrivalTime[i] <= currentTime && !processed[i])
            {
                q.push(i);
                processed[i] = true;
            }
        }

        if (remainingTime[currentProcess] > 0)
        {
            q.push(currentProcess);
        }
    }

    for (int i = 0; i < numberOfProcesses; i++)
    {
        turnAroundTime[i] = completionTime[i] - arrivalTime[i];
        waitingTime[i] = turnAroundTime[i] - burstTime[i];
        responseTime[i] = CPUFirstTime[i] - arrivalTime[i];
    }
}

void RoundRobinAlgorithm::findAverageTime()
{
    for (int i = 0; i < numberOfProcesses; i++)
    {
        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];
    }
}

void RoundRobinAlgorithm::printTable()
{
    std::cout << "\nRound Robin Algorithm\n";
    std::cout << std::left << std::setw(10) << "Process"
              << std::setw(15) << "Arrival Time"
              << std::setw(13) << "Burst Time"
              << std::setw(18) << "Completion Time"
              << std::setw(15) << "Waiting Time"
              << std::setw(18) << "Turnaround Time"
              << std::setw(16) << "Response Time" << std::endl;

    for (int i = 0; i < numberOfProcesses; i++)
    {
        std::cout << std::left << std::setw(10) << i + 1
                  << std::setw(15) << arrivalTime[i]
                  << std::setw(13) << burstTime[i]
                  << std::setw(18) << completionTime[i]
                  << std::setw(15) << waitingTime[i]
                  << std::setw(18) << turnAroundTime[i]
                  << std::setw(16) << responseTime[i] << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Average Waiting Time: " << (double)totalWaitingTime / numberOfProcesses << std::endl;
    std::cout << "Average Turnaround Time: " << (double)totalTurnAroundTime / numberOfProcesses << std::endl;
}

RoundRobinAlgorithm::~RoundRobinAlgorithm()
{
}