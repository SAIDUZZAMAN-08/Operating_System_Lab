//Race condition example

#include <iostream>
#include <thread>
#include <semaphore.h>
#include <unistd.h>   // for sleep()
using namespace std;

int shared = 1;    // shared variable
//sem_t s;           // semaphore

void fun1() {

    //sem_wait(&s);  // lock

    int x = shared;
    cout << "Thread 1 reads the value as " << x << endl;
    x++;
    cout << "Local updation by Thread 1: " << x << endl;

    sleep(1);  // simulate delay

    shared = x;
    cout << "Value of shared variable updated by Thread 1 is: " << shared << endl;

    //sem_post(&s);  // unlock
}

void fun2() {
    //sem_wait(&s);  // lock

    int y = shared;
    cout << "Thread 2 reads the value as " << y << endl;
    y--;
    cout << "Local updation by Thread 2: " << y << endl;

    sleep(1);  // simulate delay

    shared = y;
    cout << "Value of shared variable updated by Thread 2 is: " << shared << endl;

    //sem_post(&s);  // unlock
}

int main() {
    //sem_init(&s, 0, 1); // initialize binary semaphore

    thread t1(fun1);
    thread t2(fun2);

    t1.join();
    t2.join();

    cout << "Final value of shared variable is: " << shared << endl;

    //sem_destroy(&s); // destroy semaphore
    return 0;
}




// Solving with mutex

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

int sv = 1;     // shared variable
mutex mtx;      // mutex for synchronization

void fun1(){
    lock_guard<mutex>lock(mtx);

    int x=sv;

    cout << "Thread 1 reads the value as " << x << endl;
    x++;
    cout << "Local updation by Thread 1: " << x << endl;

    this_thread::sleep_for(chrono::seconds(1));  // simulate delay

    sv = x;
    cout << "Value of shared variable updated by Thread 1 is: " << sv << endl;
}

void fun2(){
    lock_guard<mutex>lock(mtx);

    int y=sv;

    cout << "Thread 2 reads the value as " << y << endl;
    y--;
    cout << "Local updation by Thread 2: " << y << endl;

    this_thread::sleep_for(chrono::seconds(1));  // simulate delay

    sv = y;
    cout << "Value of shared variable updated by Thread 1 is: " << sv << endl;
}

int main() {
    thread t1(fun1);
    thread t2(fun2);

    t1.join();
    t2.join();

    cout << "Final value of shared variable is: " << sv << endl;
    return 0;
}


//solving with semaphore

#include <iostream>
#include <thread>
#include <semaphore.h>
#include <chrono>

using namespace std;

int sv = 1;    // shared variable
sem_t sem;     // semaphore for synchronization

void fun1() {
    sem_wait(&sem);  // wait (lock)

    int x = sv;

    cout << "Thread 1 reads the value as " << x << endl;
    x++;
    cout << "Local updation by Thread 1: " << x << endl;

    this_thread::sleep_for(chrono::seconds(1)); // simulate delay

    sv = x;
    cout << "Value of shared variable updated by Thread 1 is: " << sv << endl;

    sem_post(&sem);  // signal (unlock)
}

void fun2() {
    sem_wait(&sem);  // wait (lock)

    int y = sv;

    cout << "Thread 2 reads the value as " << y << endl;
    y--;
    cout << "Local updation by Thread 2: " << y << endl;

    this_thread::sleep_for(chrono::seconds(1)); // simulate delay

    sv = y;
    cout << "Value of shared variable updated by Thread 2 is: " << sv << endl;

    sem_post(&sem);  // signal (unlock)
}

int main() {
    sem_init(&sem, 0, 1); // initialize binary semaphore

    thread t1(fun1);
    thread t2(fun2);

    t1.join();
    t2.join();

    cout << "Final value of shared variable is: " << sv << endl;

    sem_destroy(&sem); // destroy semaphore
    return 0;
}

