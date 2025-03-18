#include <stdio.h>
struct Process
{
    int pid, arrival, burst, completion, waiting, turnaround;
};
int main()
{
    struct Process p[10], temp;
    int n, time = 0, completed = 0, shortest;
    float total_wait = 0, total_turn = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        p[i].pid = i + 1;
        printf("Enter arrival and burst time for process %d: ", p[i].pid);
        scanf("%d %d", &p[i].arrival, &p[i].burst);
        p[i].completion = 0;
    }
    for (int i = 0; i < n - 1; i++)
      {
        for (int j = 0; j < n - i - 1; j++)
          {
            if (p[j].arrival > p[j + 1].arrival) 
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    while (completed < n) 
    {
        shortest = -1;
        for (int i = 0; i < n; i++) 
        {
            if (p[i].completion == 0 && p[i].arrival <= time &&
                (shortest == -1 || p[i].burst < p[shortest].burst))
                shortest = i;
        }
        if (shortest == -1)
        {
            time++;
            continue;
        }
        time += p[shortest].burst;
        p[shortest].completion = time;
        p[shortest].turnaround = p[shortest].completion - p[shortest].arrival;
        p[shortest].waiting = p[shortest].turnaround - p[shortest].burst;
        total_wait += p[shortest].waiting;
        total_turn += p[shortest].turnaround;
        completed++;
    }
    printf("\nPID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival, p[i].burst,
               p[i].completion, p[i].turnaround, p[i].waiting);
    }
    printf("\nAverage Waiting Time: %.2f\n", total_wait / n);
    printf("Average Turnaround Time: %.2f\n", total_turn / n);
    return 0;
}
