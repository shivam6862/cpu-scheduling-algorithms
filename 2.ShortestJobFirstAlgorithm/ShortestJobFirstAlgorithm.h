#ifndef SHORTESTJOBFIRSTALGORITHM_H
#define SHORTESTJOBFIRSTALGORITHM_H
#include <string>
#include <vector>

class ShortestJobFirstAlgorithm
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
    ShortestJobFirstAlgorithm(std::vector<int> &arrivalTime, std::vector<int> &burstTime);
    void findCompletionTime();
    void findAverageTime();
    void printTable();
    ~ShortestJobFirstAlgorithm();
};

#endif