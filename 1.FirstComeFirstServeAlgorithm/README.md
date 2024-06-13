# First Come First Serve Scheduling Algorithm

This project implements the First Come First Serve (FCFS) scheduling algorithm in C++. FCFS is the simplest type of scheduling algorithm that schedules processes in the order of their arrival times.

## Overview

The FCFS scheduling algorithm is a non-preemptive scheduling algorithm. This means that once a process starts its execution, it cannot be interrupted until it finishes. The processes are executed in the order they arrive in the ready queue. This algorithm is easy to understand and implement but can lead to the "convoy effect," where shorter processes have to wait for a longer process to complete.

## Codebase

The codebase consists of a single C++ file: `FirstComeFirstServe.cpp`. This file defines a `FirstComeFirstServe` class that represents a scheduler using the FCFS algorithm.

### Class: FirstComeFirstServe

The `FirstComeFirstServe` class has the following methods:

- **Constructor**: `FirstComeFirstServe(std::vector<int> &arrivalTime, std::vector<int> &burstTime)`

  - This initializes the class with the arrival times and burst times of the processes. It stores these values and sets up other necessary data structures.

- **findCompletionTime()**:

  - Calculates the completion time for each process. The completion time of a process is the time at which it finishes execution. It is determined by adding the burst time of the process to the start time (which is the completion time of the previous process).

- **findWaitingTime()**:

  - Calculates the waiting time for each process. The waiting time is the total time a process spends waiting in the ready queue. It is determined by subtracting the arrival time and burst time from the completion time.

- **findTurnAroundTime()**:

  - Calculates the turnaround time for each process. The turnaround time is the total time taken from the arrival to the completion of the process. It is determined by subtracting the arrival time from the completion time.

- **findResponseTime()**:

  - Calculates the response time for each process. The response time is the time from the arrival of the process to the first time it gets the CPU. For FCFS, this is the same as the waiting time since the process starts execution immediately once it gets the CPU.

- **findAverageTime()**:

  - Calculates the average waiting time and the average turnaround time. These metrics provide an overall sense of how efficiently the scheduler is performing.

- **printTable()**:

  - Prints a table that shows the process number, arrival time, burst time, completion time, turnaround time, waiting time, and response time for each process. This provides a detailed view of the scheduling results for each process.

- **printGanttChart()**:

  - Prints a Gantt chart that visually represents the scheduling of the processes. The Gantt chart shows the start and finish times of each process, providing a visual timeline of process execution.

- **Destructor**: `~FirstComeFirstServe()`
  - This is the destructor of the class. It prints a message indicating that the scheduling algorithm has ended.

## How to Run

To compile the program, use the following command:

```bash
g++ main.cpp FirstComeFirstServe.cpp -o output
```

To execute the program, use the following command:

```bash
./output
```
