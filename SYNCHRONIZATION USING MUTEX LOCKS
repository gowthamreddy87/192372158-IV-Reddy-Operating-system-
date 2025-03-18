#include <stdio.h>
#include <windows.h>
int counter = 0;
CRITICAL_SECTION mutex;
DWORD WINAPI threadFunction(LPVOID arg) {
    int i;
    for (i = 0; i < 1000000; ++i) {
        EnterCriticalSection(&mutex); // Lock the critical section
        counter++; // Increment counter
        LeaveCriticalSection(&mutex); // Unlock the critical section
    }
    return 0;
}
int main() {
    // Initialize the critical section
    InitializeCriticalSection(&mutex);
    HANDLE thread1, thread2;
    // Create threads
    thread1 = CreateThread(NULL, 0, threadFunction, NULL, 0, NULL);
    thread2 = CreateThread(NULL, 0, threadFunction, NULL, 0, NULL);
    // Wait for the threads to finish
    WaitForSingleObject(thread1, INFINITE);
    WaitForSingleObject(thread2, INFINITE);
    // Clean up the critical section
    DeleteCriticalSection(&mutex);
    // Print the final value of the counter
    printf("Final counter value: %d\n", counter);
    return 0;
}
