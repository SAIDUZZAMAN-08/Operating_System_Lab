#include <iostream>
#include <thread>
#include <semaphore.h>   // POSIX semaphores
#include <queue>
#include <mutex>
#include <chrono>

using namespace std;

const int BUFFER_SIZE = 5;
queue<int> buffer;
mutex mtx;

sem_t emptySlots;  // Count of empty buffer slots
sem_t fullSlots;   // Count of filled buffer slots

void producer(int id) {
    int item = 0;
    while (true) {
        this_thread::sleep_for(chrono::milliseconds(500));
        item++;

        sem_wait(&emptySlots);  // Wait if buffer is full
        mtx.lock();

        buffer.push(item);
        cout << "Producer " << id << " produced item " << item
             << " | Buffer size: " << buffer.size() << endl;

        mtx.unlock();
        sem_post(&fullSlots);  // Signal item available
    }
}

void consumer(int id) {
    while (true) {
        sem_wait(&fullSlots);  // Wait if buffer empty
        mtx.lock();

        int item = buffer.front();
        buffer.pop();
        cout << "Consumer " << id << " consumed item " << item
             << " | Buffer size: " << buffer.size() << endl;

        mtx.unlock();
        sem_post(&emptySlots);  // Signal empty slot

        this_thread::sleep_for(chrono::milliseconds(800));
    }
}

int main() {
    sem_init(&emptySlots, 0, BUFFER_SIZE);
    sem_init(&fullSlots, 0, 0);

    thread p1(producer, 1);
    thread p2(producer, 2);
    thread c1(consumer, 1);
    thread c2(consumer, 2);

    p1.join();
    p2.join();
    c1.join();
    c2.join();

    sem_destroy(&emptySlots);
    sem_destroy(&fullSlots);
    return 0;
}
