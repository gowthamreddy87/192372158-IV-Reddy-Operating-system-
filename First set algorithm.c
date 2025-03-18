#include <stdio.h>
void firstFit(int b[], int m, int p[], int n) {
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (b[j] >= p[i]) {
                printf("Process %d allocated to Block %d\n", i+1, j+1);
                b[j] -= p[i];
                break;
            }
        }
        if (j == m) printf("Process %d not allocated\n", i+1);
    }
}
int main() {
    int b[] = {100, 500, 200, 300}, p[] = {212, 417, 112, 426};
    firstFit(b, 4, p, 4);
    return 0;
}
