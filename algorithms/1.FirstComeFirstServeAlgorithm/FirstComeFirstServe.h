#ifndef FIRSTCOMEFIRSTSERVE_H
#define FIRSTCOMEFIRSTSERVE_H
#include <string>
#include <vector>

class FirstComeFirstServe
{
private:
    std::vector<int> arrivalTime;
    std::vector<int> burstTime;
    std::vector<int> completionTime;
    std::vector<int> waitingTime;
    std::vector<int> turnAroundTime;
    std::vector<int> responseTime;
    int numberOfProcesses;
    int totalWaitingTime;
    int totalTurnAroundTime;

public:
    FirstComeFirstServe(std::vector<int> &arrivalTime, std::vector<int> &burstTime);
    void findCompletionTime();
    void findWaitingTime();
    void findTurnAroundTime();
    void findResponseTime();
    void findAverageTime();
    void printTable();
    void printGanttChart();
    ~FirstComeFirstServe();
};

#endif