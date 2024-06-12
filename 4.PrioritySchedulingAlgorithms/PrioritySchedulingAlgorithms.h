#ifndef PRIORITYSCHEDULINGALGORITHMS_H
#define PRIORITYSCHEDULINGALGORITHMS_H
#include <string>
#include <vector>

class PrioritySchedulingAlgorithms
{
private:
    std::vector<int> arrivalTime;
    std::vector<int> burstTime;
    std::vector<int> priority;
    std::vector<int> completionTime;
    std::vector<int> waitingTime;
    std::vector<int> turnAroundTime;
    std::vector<int> responseTime;
    int numberOfProcesses;
    int totalWaitingTime;
    int totalTurnAroundTime;

public:
    PrioritySchedulingAlgorithms(std::vector<int> &arrivalTime, std::vector<int> &burstTime, std::vector<int> &priority);
    void findCompletionTime();
    void findAverageTime();
    void printTable();
    ~PrioritySchedulingAlgorithms();
};

#endif