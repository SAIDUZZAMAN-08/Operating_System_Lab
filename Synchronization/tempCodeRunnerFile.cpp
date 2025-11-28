#include <iostream>
// #include <thread>
// #include <mutex>
// #include <semaphore.h>
// #include <vector>
// #include <chrono>
// using namespace std;

// int item = 0;
// const int Buff = 5;
// vector<int> buff;
// mutex mtx;          // Protect buffer and item

// sem_t emt; // empty slots
// sem_t full; // full slots

// void producer(int id) {
//     while (true) {
//         this_thread::sleep_for(chrono::seconds(1)); // simulate production time

//         int producedItem;
//         {
//             lock_guard<mutex> lock(mtx);
//             item++;                  // increment shared item safely
//             producedItem = item;
//         }

//         sem_wait(&emt); // wait for empty slot
//         {
//             lock_guard<mutex> lock(mtx);
//             buff.push_back(producedItem);
//             cout << "Producer " << id << " produced: " << producedItem << endl;
//         }
//         sem_post(&full); // signal new full slot
//     }
// }

// void consumer(int id) {
//     while (true) {
//         sem_wait(&full); // wait for full slot

//         int consumedItem;
//         {
//             lock_guard<mutex> lock(mtx);
//             consumedItem = buff.back();
//             buff.pop_back();
//             cout << "Consumer " << id << " consumed: " << consumedItem << endl;
//         }

//         sem_post(&emt); // signal empty slot
//         this_thread::sleep_for(chrono::seconds(1)); // simulate consumption
//     }
// }

// int main() {
//     sem_init(&emt, 0, Buff); // all slots empty initially
//     sem_init(&full, 0, 0);   // no items initially

//     thread p1(producer, 1);
//     thread p2(producer, 2);
//     thread c1(consumer, 1);
//     thread c2(consumer, 2);

//     p1.join();
//     p2.join();
//     c1.join();
//     c2.join();

//     sem_destroy(&emt);
//     sem_destroy(&full);

//     return 0;
// }