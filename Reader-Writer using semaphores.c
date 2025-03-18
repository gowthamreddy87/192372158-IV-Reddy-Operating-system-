#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
sem_t mutex, write_mutex;
int read_count = 0;
void *reader(void *arg) {
    sem_wait(&mutex);
    read_count++;
    if (read_count == 1) sem_wait(&write_mutex);
    sem_post(&mutex);
    printf("Reading\n");
    sem_wait(&mutex);
    read_count--;
    if (read_count == 0) sem_post(&write_mutex);
    sem_post(&mutex);
}
void *writer(void *arg) {
    sem_wait(&write_mutex);
    printf("Writing\n");
    sem_post(&write_mutex);
}
int main() {
    pthread_t r1, r2, w1;
    sem_init(&mutex, 0, 1);
    sem_init(&write_mutex, 0, 1);
    pthread_create(&r1, NULL, reader, NULL);
    pthread_create(&r2, NULL, reader, NULL);
    pthread_create(&w1, NULL, writer, NULL);
    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(w1, NULL);
    sem_destroy(&mutex);
    sem_destroy(&write_mutex);
    return 0;
}
