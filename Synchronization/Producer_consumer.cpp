#include <iostream>
#include <thread>
#include <mutex>
#include <semaphore.h>
#include <vector>
#include <unistd.h>
using namespace std;

int item = 0;
const int Buff = 5;
vector<int> buff;
mutex mtx;

sem_t emt;  
sem_t full; 

void producer(int id) {
    while (true) {
        sleep(1); 
        sem_wait(&emt);  

        int producedItem;
        {
            lock_guard<mutex> lock(mtx); 
            item++;
            producedItem = item;
            buff.push_back(producedItem);
            cout << "Producer " << id << " produced: " << producedItem << endl;
        }

        sem_post(&full); 
    }
}

void consumer(int id) {
    while (true) {
        sem_wait(&full); 

        int consumedItem;
        {
            lock_guard<mutex> lock(mtx); 
            consumedItem = buff.back();
            buff.pop_back();
            cout << "Consumer " << id << " consumed: " << consumedItem << endl;
        }

        sem_post(&emt); 
        sleep(1);       
    }
}

int main() {
    sem_init(&emt, 0, Buff); // Buff empty slots initially
    sem_init(&full, 0, 0);   // 0 full slots initially

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
