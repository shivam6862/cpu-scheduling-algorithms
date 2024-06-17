# CPU Scheduling Algorithms

CPU scheduling algorithms are crucial for managing how processes are assigned to the CPU for execution. Effective scheduling maximizes CPU utilization, minimizes wait time, and ensures fair resource distribution among processes. Here’s an in-depth look at various CPU scheduling algorithms and key terms used in scheduling:

## Cloning the Repository

To get started, first clone the repository to your local machine:

```bash
git clone https://github.com/shivam6862/cpu-scheduling-algorithms
cd cpu-scheduling-algorithms
```

## Frontend Setup

The frontend is built using modern web technologies and requires Node.js to run. Follow these steps to set up and start the frontend development server:

1. Navigate to the `frontend` directory:

   ```bash
   cd frontend
   ```

2. Install the necessary dependencies and start the development server:
   ```bash
   npm install
   npm run build
   npm start
   ```

## Backend Setup

The backend is implemented in Python. It uses a virtual environment for managing dependencies. Follow these steps to set up the backend:

1. Create a virtual environment:

   ```bash
   python -m venv .venv
   ```

2. Activate the virtual environment:

   - On Windows:

     ```bash
     ./venv/Scripts/activate
     ```

   - On macOS/Linux:
     ```bash
     source .venv/bin/activate
     ```

3. Install the required Python packages:

   ```bash
   pip install -r requirements.txt
   ```

4. Run the backend application:
   ```bash
   python mani.py
   ```

## Types of Scheduling Algorithms

1. **First Come First Serve (FCFS):**

   - **Description:** Processes are executed in the order they arrive in the ready queue.
   - **Advantages:**
     - Simple to implement.
     - Predictable as the order of execution is straightforward.
   - **Disadvantages:**
     - Can lead to long waiting times, especially for shorter processes if a long process arrives first (Convoy effect).
     - Not suitable for time-sharing systems.

2. **Shortest Job First (SJF):**

   - **Description:** Executes the process with the shortest burst time first.
   - **Advantages:**
     - Minimizes average waiting time and turnaround time.
   - **Disadvantages:**
     - Difficult to predict the burst time accurately.
     - Can lead to starvation if short processes keep arriving.

3. **Round Robin (RR):**

   - **Description:** Each process gets a fixed time slice (quantum) in a cyclic order.
   - **Advantages:**
     - Fair allocation of CPU time.
     - Good for time-sharing systems as it ensures no process waits too long.
   - **Disadvantages:**
     - Average waiting time can be high.
     - Performance heavily depends on the length of the time quantum.

4. **Pre-emptive Priority Scheduling:**
   - **Description:** Processes are assigned priorities, and the CPU is allocated to the process with the highest priority. If a new process arrives with a higher priority than the current running process, the CPU is preempted and assigned to the new process.
   - **Advantages:**
     - Can ensure important processes get more CPU time.
   - **Disadvantages:**
     - Can lead to starvation of low-priority processes.
     - Priority inversion can occur, where a high-priority process is waiting for a lower-priority one.

## CPU Scheduling Terms

- **Arrival Time:**

  - **Definition:** The time at which a process arrives in the ready queue.
  - **Example:** If a process arrives at the system at 0 seconds, its arrival time is 0.

- **Burst Time:**

  - **Definition:** The total time required by a process for its execution on the CPU.
  - **Example:** If a process needs 5 seconds of CPU time to complete, its burst time is 5 seconds.

- **Completion Time:**

  - **Definition:** The time at which a process completes its execution and exits the CPU.
  - **Example:** If a process starts at 2 seconds and finishes at 7 seconds, its completion time is 7 seconds.

- **Turnaround Time:**

  - **Definition:** The total time taken by a process from arrival to completion. It is calculated as:
    - **Example:** If a process arrives at 0 seconds and completes at 10 seconds, its turnaround time is 10 seconds.

- **Waiting Time:**

  - **Definition:** The total time a process spends waiting in the ready queue. It is calculated as:
  - **Example:** If a process has a turnaround time of 10 seconds and a burst time of 5 seconds, its waiting time is 5 seconds.

- **Response Time:**
  - **Definition:** The time taken from when a process arrives in the ready queue to the first time it gets the CPU. It is important in interactive systems where the promptness of response is crucial.
  - **Example:** If a process arrives at 0 seconds and gets the CPU for the first time at 2 seconds, its response time is 2 seconds.

## Frontend Page

![image.png](/image.png)

## Summary

- **FCFS** is simple but can cause long waiting times for short processes.
- **SJF** is efficient but requires knowing the burst times in advance.
- **Round Robin** ensures fair CPU allocation but can lead to high average waiting times if the time quantum is not well chosen.
- **Pre-emptive Priority Scheduling** can prioritize important processes but can cause lower-priority processes to starve.
