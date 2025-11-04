#include <iostream>
#include <thread>
#include <semaphore.h>

using namespace std;

int counter = 0;
sem_t sem;

void increment(int n) {
    for (int i = 0; i < n; i++) {
        sem_wait(&sem); // lock
        counter++;
        sem_post(&sem); // unlock
    }
}

void decrement(int n) {
    for (int i = 0; i < n; i++) {
        sem_wait(&sem); // lock
        counter--;
        sem_post(&sem); // unlock
    }
}

int main() {
    int n = 1000000;

    sem_init(&sem, 0, 1); // binary semaphore

    thread t1(increment, n);
    thread t2(decrement, n);

    t1.join();
    t2.join();

    cout << "Final counter with semaphore: " << counter << endl;

    sem_destroy(&sem);
    return 0;
}
