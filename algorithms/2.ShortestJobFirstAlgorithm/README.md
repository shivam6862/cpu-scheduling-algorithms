# Shortest Job First Scheduling Algorithm

This project implements the Shortest Job First (SJF) scheduling algorithm in C++. SJF is a type of scheduling algorithm that schedules processes based on their burst times. It aims to minimize the average waiting time by executing the shortest jobs first.

## Overview

The SJF scheduling algorithm is a non-preemptive scheduling algorithm that selects the process with the smallest burst time for execution next. This algorithm can significantly improve performance compared to the First Come First Serve (FCFS) algorithm, especially in systems where process burst times vary widely. However, it requires precise knowledge of the burst time of each process, which might not always be possible in practice.

## Codebase

The codebase consists of a single C++ file: `ShortestJobFirstAlgorithm.cpp`. This file defines a `ShortestJobFirstAlgorithm` class that represents a scheduler using the SJF algorithm.

### Class: ShortestJobFirstAlgorithm

The `ShortestJobFirstAlgorithm` class has the following methods:

- **Constructor**: `ShortestJobFirstAlgorithm(std::vector<int> &arrivalTime, std::vector<int> &burstTime)`

  - Initializes the class with the arrival times and burst times of the processes. It stores these values and sets up other necessary data structures.

- **findCompletionTime()**:

  - Calculates the completion time for each process. The completion time is the time at which a process finishes execution. The algorithm selects the process with the smallest burst time that has arrived and schedules it next.

  - Calculates the waiting time for each process. The waiting time is the total time a process spends waiting in the ready queue. It is determined by subtracting the arrival time and burst time from the completion time.

  - Calculates the turnaround time for each process. The turnaround time is the total time taken from the arrival to the completion of the process. It is determined by subtracting the arrival time from the completion time.

  - Calculates the average waiting time and the average turnaround time. These metrics provide an overall sense of how efficiently the scheduler is performing.

- **printTable()**:

  - Prints a table that shows the process number, arrival time, burst time, completion time, turnaround time, waiting time, and response time for each process. This provides a detailed view of the scheduling results for each process.

- **Destructor**: `~ShortestJobFirstAlgorithm()`
  - Clears all the vectors and prints a message indicating that the SJF algorithm object has been destroyed.

## How to Run

To compile the program, use the following command:

```bash
g++ main.cpp ShortestJobFirstAlgorithm.cpp -o output
```

To execute the program, use the following command:

```bash
./output
```
