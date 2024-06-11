#ifndef ROUNDROBINALGORITHM_H
#define ROUNDROBINALGORITHM_H
#include <string>
#include <vector>

class RoundRobinAlgorithm
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
    int quantumTime;

public:
    RoundRobinAlgorithm(std::vector<int> &arrivalTime, std::vector<int> &burstTime, int quantumTime);
    void findCompletionTime();
    void findAverageTime();
    void printTable();
    ~RoundRobinAlgorithm();
};

#endif