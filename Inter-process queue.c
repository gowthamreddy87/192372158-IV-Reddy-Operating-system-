#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>
int main() {
    key_t key = 1234; 
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT); 
    char *str = (char *)shmat(shmid, NULL, 0); 
    if (fork() == 0) { 
        strcpy(str, "you are unpredictBLE");
    } else { 
        sleep(1); 
        printf("Parent reads: %s\n", str);
        shmdt(str); 
        shmctl(shmid, IPC_RMID, NULL); 
    }
    return 0;
}
