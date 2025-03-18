#include <stdio.h>
struct Process 
{
    int id, bt, pr, wt, tat;
};
int main() 
{
    int n, i, j, totalWT = 0, totalTAT = 0;
    struct Process p[20], temp;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) 
    {
        p[i].id = i + 1;
        printf("Enter burst time and priority for process p%d: ", i + 1);
        scanf("%d%d", &p[i].bt, &p[i].pr);
    }
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (p[j].pr < p[i].pr) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
    p[0].wt = 0;
    for (i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
        totalWT += p[i].wt;
    }
    for (i = 0; i < n; i++) {
        p[i].tat = p[i].wt + p[i].bt;
        totalTAT += p[i].tat;
    }
    printf("\nProcess\tPriority\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("p%d\t%d\t\t%d\t%d\t%d\n", p[i].id, p[i].pr, p[i].bt, p[i].wt, p[i].tat);
    printf("\nAverage WT = %.2f, Average TAT = %.2f\n", (float)totalWT / n, (float)totalTAT / n);
    return 0;
}
