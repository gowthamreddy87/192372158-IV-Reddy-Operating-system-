#include <stdio.h>
void worstFit(int blockSize[], int m, int processSize[], int n) {
    for (int i = 0; i < n; i++) {
        int maxIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i] && (maxIdx == -1 || blockSize[j] > blockSize[maxIdx])) 
                maxIdx = j;
        }
        if (maxIdx != -1) {
            blockSize[maxIdx] -= processSize[i];
            printf("Process %d allocated to block %d\n", i+1, maxIdx+1);
        } else {
            printf("Process %d not allocated\n", i+1);
        }
    }
}
int main() {
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    worstFit(blockSize, 5, processSize, 4);
    return 0;
}
 
