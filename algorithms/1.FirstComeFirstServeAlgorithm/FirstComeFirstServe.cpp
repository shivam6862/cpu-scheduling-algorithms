#include <iostream>
#include <string>
#include <iomanip>
#include "FirstComeFirstServe.h"

FirstComeFirstServe::FirstComeFirstServe(std::vector<int> &arrivalTime, std::vector<int> &burstTime)
{
    this->arrivalTime = arrivalTime;
    this->burstTime = burstTime;
    this->numberOfProcesses = arrivalTime.size();
    this->totalWaitingTime = 0;
    this->totalTurnAroundTime = 0;
}

void FirstComeFirstServe::findCompletionTime()
{
    completionTime.resize(numberOfProcesses);
    completionTime[0] = arrivalTime[0] + burstTime[0];
    for (int i = 1; i < numberOfProcesses; i++)
    {
        completionTime[i] = std::max(completionTime[i - 1], arrivalTime[i]) + burstTime[i];
    }
}

void FirstComeFirstServe::findWaitingTime()
{
    waitingTime.resize(numberOfProcesses);
    waitingTime[0] = 0;
    for (int i = 1; i < numberOfProcesses; i++)
    {
        waitingTime[i] = completionTime[i - 1] - arrivalTime[i];
        if (waitingTime[i] < 0)
        {
            waitingTime[i] = 0;
        }
    }
}

void FirstComeFirstServe::findTurnAroundTime()
{
    turnAroundTime.resize(numberOfProcesses);
    for (int i = 0; i < numberOfProcesses; i++)
    {
        turnAroundTime[i] = burstTime[i] + waitingTime[i];
    }
}

void FirstComeFirstServe::findResponseTime()
{
    responseTime.resize(numberOfProcesses);
    for (int i = 0; i < numberOfProcesses; i++)
    {
        responseTime[i] = waitingTime[i];
    }
}

void FirstComeFirstServe::findAverageTime()
{
    for (int i = 0; i < numberOfProcesses; i++)
    {
        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];
    }
}

void FirstComeFirstServe::printTable()
{
    std::cout << "First Come First Serve Scheduling Algorithm\n";
    std::cout << std::left << std::setw(10) << "Process"
              << std::setw(15) << "Arrival Time"
              << std::setw(12) << "Burst Time"
              << std::setw(17) << "Completion Time"
              << std::setw(18) << "Turnaround Time"
              << std::setw(14) << "Waiting Time"
              << std::setw(15) << "Response Time" << "\n";

    for (int i = 0; i < numberOfProcesses; i++)
    {
        std::cout << std::left << std::setw(10) << i + 1
                  << std::setw(15) << arrivalTime[i]
                  << std::setw(12) << burstTime[i]
                  << std::setw(17) << completionTime[i]
                  << std::setw(18) << turnAroundTime[i]
                  << std::setw(14) << waitingTime[i]
                  << std::setw(15) << responseTime[i] << "\n";
    }

    std::cout << "\nAverage Waiting Time: " << (float)totalWaitingTime / numberOfProcesses << "\n";
    std::cout << "Average Turnaround Time: " << (float)totalTurnAroundTime / numberOfProcesses << "\n";
}

void FirstComeFirstServe::printGanttChart()
{
    std::cout << "\nGantt Chart\n";

    for (int i = 0; i < numberOfProcesses; i++)
    {
        std::cout << " ";
        for (int j = 0; j < burstTime[i]; j++)
        {
            std::cout << "--";
        }
        std::cout << " ";
    }
    std::cout << "\n|";

    for (int i = 0; i < numberOfProcesses; i++)
    {
        for (int j = 0; j < burstTime[i] - 1; j++)
        {
            std::cout << " ";
        }
        std::cout << "P" << i + 1;
        for (int j = 0; j < burstTime[i] - 1; j++)
        {
            std::cout << " ";
        }
        std::cout << "|";
    }
    std::cout << "\n";

    for (int i = 0; i < numberOfProcesses; i++)
    {
        std::cout << " ";
        for (int j = 0; j < burstTime[i]; j++)
        {
            std::cout << "--";
        }
        std::cout << " ";
    }
    std::cout << "\n";

    std::cout << "0";
    for (int i = 0; i < numberOfProcesses; i++)
    {
        for (int j = 0; j < burstTime[i]; j++)
        {
            std::cout << "  ";
        }
        if (completionTime[i] > 9)
        {
            std::cout << "\b";
        }
        std::cout << completionTime[i];
    }
    std::cout << "\n";
}

FirstComeFirstServe::~FirstComeFirstServe()
{
}