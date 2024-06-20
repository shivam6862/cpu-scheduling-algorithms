# Priority Scheduling Algorithm

This project implements the Priority Scheduling algorithm in C++. Priority Scheduling is a type of scheduling algorithm that schedules processes based on their priority. Processes with higher priority are executed first.

## Overview

The Priority Scheduling algorithm is a preemptive or non-preemptive scheduling algorithm where each process is assigned a priority. The process with the highest priority (usually the lowest numerical value) is selected for execution first. This algorithm can be useful in systems where certain tasks are more critical than others and need to be completed sooner. However, it can lead to process starvation, where lower priority processes may never get executed if higher priority processes keep arriving.

## Codebase

The codebase consists of a single C++ file: `PrioritySchedulingAlgorithms.cpp`. This file defines a `PrioritySchedulingAlgorithms` class that represents a scheduler using the Priority Scheduling algorithm.

### Class: PrioritySchedulingAlgorithms

The `PrioritySchedulingAlgorithms` class has the following methods:

- **Constructor**: `PrioritySchedulingAlgorithms(std::vector<int> &arrivalTime, std::vector<int> &burstTime, std::vector<int> &priority)`

  - Initializes the class with the arrival times, burst times, and priorities of the processes. It stores these values and sets up other necessary data structures.

- **findCompletionTime()**:

  - Calculates the completion time for each process. The completion time is the time at which a process finishes execution. The algorithm selects the process with the highest priority (lowest numerical value) that has arrived and schedules it next.

  - Calculates the waiting time for each process. The waiting time is the total time a process spends waiting in the ready queue. It is determined by subtracting the arrival time and burst time from the completion time.

  - Calculates the turnaround time for each process. The turnaround time is the total time taken from the arrival to the completion of the process. It is determined by subtracting the arrival time from the completion time.

  - Calculates the average waiting time and the average turnaround time. These metrics provide an overall sense of how efficiently the scheduler is performing.

- **printTable()**:

  - Prints a table that shows the process number, priority, arrival time, burst time, completion time, waiting time, turnaround time, and response time for each process. This provides a detailed view of the scheduling results for each process.

- **Destructor**: `~PrioritySchedulingAlgorithms()`
  - Prints a message indicating that the Priority Scheduling Algorithm object has been destroyed.

## How to Run

To compile the program, use the following command:

```bash
g++ main.cpp PrioritySchedulingAlgorithms.cpp -o output
```

To execute the program, use the following command:

```bash
./output
```
