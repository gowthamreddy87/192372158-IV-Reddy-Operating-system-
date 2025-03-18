#include <stdio.h>
void roundRobin(int n, int bt[], int quantum) 
{
    int wt[n], tat[n], rem_bt[n], t = 0, done;
    for (int i = 0; i < n; i++) rem_bt[i] = bt[i];
    do 
    {
        done = 1;
        for (int i = 0; i < n; i++) 
        {
            if (rem_bt[i] > 0) 
            {
                done = 0;
                if (rem_bt[i] > quantum) 
                {
                    t += quantum;
                    rem_bt[i] -= quantum;
                }
                else 
                {
                    t += rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
    } 
    while (!done);
    for (int i = 0; i < n; i++) tat[i] = bt[i] + wt[i];
    printf("\nP# BT WT TAT\n");
    for (int i = 0; i < n; i++)
        printf("%d  %d  %d  %d\n", i + 1, bt[i], wt[i], tat[i]);
}
int main() 
{
    int n, quantum;
    printf("Processes: ");
    scanf("%d", &n);
    int bt[n];
    printf("Burst Times: ");
    for (int i = 0; i < n; i++) scanf("%d", &bt[i]);
    printf("Quantum: ");
    scanf("%d", &quantum);
    roundRobin(n, bt, quantum);
    return 0;
}
