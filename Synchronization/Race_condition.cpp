#include <iostream>
#include <thread>

using namespace std;

int counter = 0; // shared variable

void increment(int n) {
    for (int i = 0; i < n; i++) {
        counter++; // race condition here
    }
}

void decrement(int n) {
    for (int i = 0; i < n; i++) {
        counter--; // race condition here
    }
}

int main() {
    int n = 1000000;

    thread t1(increment, n);
    thread t2(decrement, n);

    t1.join();
    t2.join();

    cout << "Final counter without synchronization: " << counter << endl;
    return 0;
}
