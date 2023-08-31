#include <stdio.h>

#define MAX_PROCESSES 5
#define TIME_QUANTUM 2

struct Process {
    int id;
    int burst_time;
};

void roundRobin(struct Process processes[], int n) {
    int remaining_time[MAX_PROCESSES];
    int time = 0;
    
    // Initialize remaining_time for each process
    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time;
    }
    
    while (1) {
        int allProcessesDone = 1;
        
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                allProcessesDone = 0;
                
                // Execute the process for the time quantum or its remaining time, whichever is smaller
                int executionTime = (remaining_time[i] < TIME_QUANTUM) ? remaining_time[i] : TIME_QUANTUM;
                
                printf("Time %d: Executing process %d for %d units.\n", time, processes[i].id, executionTime);
                
                remaining_time[i] -= executionTime;
                time += executionTime;
            }
        }
        
        if (allProcessesDone) {
            break;
        }
    }
}

int main() {
    struct Process processes[MAX_PROCESSES] = {
        {1, 6},
        {2, 4},
        {3, 8},
        {4, 3},
        {5, 5}
    };
    
    int n = sizeof(processes) / sizeof(processes[0]);
    
    roundRobin(processes, n);
    
    return 0;
}
