#include <iostream>
#include <thread>
#include <mutex>
#include<unistd.h>

using namespace std;

int counter = 0;
mutex mtx;

void increment(int n) {
    for (int i = 0; i < n; i++) {
        mtx.lock();
        counter++;
        cout<<"Incre"<<i<<"counter: "<<counter<<endl;
        mtx.unlock();
    }
}

void decrement(int n) {
    for (int i = 0; i < n; i++) {
        mtx.lock();
        counter--;
        cout<<"decre"<<i<<"counter: "<<counter<<endl;
        mtx.unlock();
    }
}

int main() {
    int n = 10000;

    thread t1(increment, n);
    thread t2(decrement, n);

    t1.join();
    t2.join();

    cout << "Final counter with mutex: " << counter << endl;
    return 0;
}
