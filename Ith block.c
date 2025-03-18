#include <stdio.h>
#include <string.h>

int main() {
    char file[5][20] = {"Record1", "Record2", "Record3", "Record4", "Record5"};
    int n = 5, access_index;

    printf("Enter record index to access (0-%d): ", n - 1);
    scanf("%d", &access_index);

    if (access_index >= n || access_index < 0) {
        printf("Invalid index!\n");
        return 1;
    }

    printf("Accessing records sequentially:\n");
    for (int i = 0; i <= access_index; i++) {
        printf("%s\n", file[i]);
    }

    return 0;
}