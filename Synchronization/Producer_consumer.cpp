#include <iostream>
#include <thread>
#include <mutex>
#include <semaphore.h>
#include <vector>
#include <unistd.h>
using namespace std;

const int Buff = 5;
vector<int> buff;
mutex mtx;

sem_t emt; // empty slots
sem_t full;  // filled slots

void producer(int id) {
    int item = 0;
    while (true) {
        sleep(1); // simulate production time
        item++;

        sem_wait(&emt); // wait for empty slot
        mtx.lock();

        buff.push_back(item);
        cout << "Producer " << id << " produced: " << item << endl;

        mtx.unlock();
        sem_post(&full); // signal that a new full slot is available
    }
}

void consumer(int id) {
    int item;
    while (true) {
        sem_wait(&full); // wait for full slot
        mtx.lock();

        item = buff.back();
        buff.pop_back();
        cout << "Consumer " << id << " consumed: " << item << endl;

        mtx.unlock();
        sem_post(&emt); // signal that an empty slot is available

        sleep(1); // simulate consumption time
    }
}

int main() {
    sem_init(&emt, 0, Buff); // Buff empty slots initially
    sem_init(&full, 0, 0);     // 0 full slots initially

    thread p1(producer, 1);
    thread p2(producer, 2);
    thread c1(consumer, 1);
    thread c2(consumer, 2);

    p1.join();
    p2.join();
    c1.join();
    c2.join();

    sem_destroy(&emt);
    sem_destroy(&full);

    return 0;
}
