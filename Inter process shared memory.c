#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
int main()
{
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    char *shared_mem = (char *)shmat(shmid, NULL, 0);
    if (fork() == 0) 
    {
        strcpy(shared_mem, "Hello from child!");
        printf("Child: Wrote to shared memory.\n");
        shmdt(shared_mem);
    } 
    else
    {
        wait(NULL);
        printf("Parent: Read from shared memory: %s\n", shared_mem);
        shmdt(shared_mem);
        shmctl(shmid, IPC_RMID, NULL);
    }
    return 0;
}
