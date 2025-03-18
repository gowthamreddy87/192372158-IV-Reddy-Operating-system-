#include <stdio.h>
#define MAX 100
typedef struct {
    int pid, arrival, burst, priority, remaining, completion, waiting, turnaround;
} Process;
int main() 
{
    Process p[MAX];
    int n, time = 0, completed = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        p[i].pid = i + 1;
        printf("Enter arrival time, burst time, priority for process %d: ", i + 1);
        scanf("%d %d %d", &p[i].arrival, &p[i].burst, &p[i].priority);
        p[i].remaining = p[i].burst;
    }
    while (completed < n) 
    {
        int shortest = -1, minPriority = __INT_MAX__;
        for (int i = 0; i < n; i++) 
            if (p[i].arrival <= time && p[i].remaining > 0 && p[i].priority < minPriority) 
            {
                minPriority = p[i].priority;
                shortest = i;
            }
        if (shortest == -1) { time++; continue; }
        p[shortest].remaining--;
        time++;
        if (p[shortest].remaining == 0) 
        {
            completed++;
            p[shortest].completion = time;
            p[shortest].turnaround = time - p[shortest].arrival;
            p[shortest].waiting = p[shortest].turnaround - p[shortest].burst;
        }
    }
    printf("\nPID\tArrival\tBurst\tPriority\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival, p[i].burst, p[i].priority, p[i].turnaround, p[i].waiting);
    return 0;
}
