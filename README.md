# CPU Scheduling Algorithms:

CPU scheduling algorithms are fundamental mechanisms used by operating systems to manage the execution of processes in a way that optimizes various performance metrics. These algorithms determine the order in which processes run, ensuring efficient use of the CPU and providing a balance between system responsiveness and resource utilization.

## Types of Scheduling Algorithms

1. **FCFS (First Come First Serve):** Processes are executed in the order they arrive.

2. **SJF (Shortest Job First):** Executes the shortest job first.

3. **SJF with Preemption:** Allows preemption of a running process if a shorter job arrives.

4. **Round Robin (RR):** Each process gets a fixed time on the CPU, then moves to the back of the queue.

5. **Pre-emptive Priority Scheduling:** Priority-based scheduling with preemption.

6. **Mix Burst Time:** Handles both CPU and I/O burst times.

7. **Multi-Level Queue Scheduling:** Processes are divided into multiple queues with different priority levels.

8. **Multilevel Feedback Queue Scheduling:** Allows processes to move between queues based on their behavior to reduce starvation.

# CPU Scheduling Terms:

- **Arrival Time:** Time when a process arrives in the ready queue.
- **Burst Time:** Time required by a process to complete its execution.
- **Completion Time:** Time at which a process completes its execution.
- **Turnaround Time:** Total time taken by a process to complete from arrival to completion.
- **Waiting Time:** Total time a process spends waiting in the ready queue.
- **Response Time:** Time taken to respond to the first input.
