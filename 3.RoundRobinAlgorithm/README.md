# Round Robin Scheduling Algorithm

This project implements the Round Robin (RR) scheduling algorithm in C++. RR is a preemptive scheduling algorithm that allocates a fixed time quantum to each process in a cyclic order, ensuring that all processes get an equal share of the CPU.

## Overview

The Round Robin scheduling algorithm is designed to improve response times in interactive systems. Each process is assigned a fixed time slice or quantum during which it can execute. If a process does not complete its burst time within this quantum, it is preempted, and the next process in the queue is scheduled to run. This cycle continues until all processes are completed. The RR algorithm helps in avoiding process starvation and is fairer compared to First Come First Serve (FCFS) and Shortest Job First (SJF).

## Codebase

The codebase consists of a single C++ file: `RoundRobinAlgorithm.cpp`. This file defines a `RoundRobinAlgorithm` class that represents a scheduler using the RR algorithm.

### Class: RoundRobinAlgorithm

The `RoundRobinAlgorithm` class has the following methods:

- **Constructor**: `RoundRobinAlgorithm(std::vector<int> &arrivalTime, std::vector<int> &burstTime, int quantumTime)`

  - Initializes the class with the arrival times and burst times of the processes, as well as the quantum time. It stores these values and sets up other necessary data structures.

- **findCompletionTime()**:

  - Calculates the completion time for each process. The completion time is the time at which a process finishes execution. The algorithm cycles through the processes, allocating the quantum time and updating the remaining burst times until all processes are completed.

- **findWaitingTime()**:

  - Calculates the waiting time for each process. The waiting time is the total time a process spends waiting in the ready queue. It is determined by subtracting the arrival time and burst time from the completion time.

- **findTurnAroundTime()**:

  - Calculates the turnaround time for each process. The turnaround time is the total time taken from the arrival to the completion of the process. It is determined by subtracting the arrival time from the completion time.

- **findAverageTime()**:

  - Calculates the average waiting time and the average turnaround time. These metrics provide an overall sense of how efficiently the scheduler is performing.

- **printTable()**:

  - Prints a table that shows the process number, arrival time, burst time, completion time, turnaround time, waiting time, and response time for each process. This provides a detailed view of the scheduling results for each process.

- **Destructor**: `~RoundRobinAlgorithm()`
  - Clears all the vectors and prints a message indicating that the RR algorithm object has been destroyed.

## How to Run

To compile the program, use the following command:

```bash
g++ main.cpp RoundRobinAlgorithm.cpp -o output
```

To execute the program, use the following command:

```bash
./output
```
