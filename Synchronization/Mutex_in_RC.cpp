#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int counter = 0;
mutex mtx;

void increment(int n) {
    for (int i = 0; i < n; i++) {
        mtx.lock();
        counter++;
        mtx.unlock();
    }
}

void decrement(int n) {
    for (int i = 0; i < n; i++) {
        mtx.lock();
        counter--;
        mtx.unlock();
    }
}

int main() {
    int n = 1000000;

    thread t1(increment, n);
    thread t2(decrement, n);

    t1.join();
    t2.join();

    cout << "Final counter with mutex: " << counter << endl;
    return 0;
}
