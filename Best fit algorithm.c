#include <stdio.h>
void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i] && (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])) 
                bestIdx = j;
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    for (int i = 0; i < n; i++) 
        printf("Process %d allocated to Block %d\n", i + 1, allocation[i] + 1);
}

int main() {
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    bestFit(blockSize, 5, processSize, 4);
    return 0;
}
