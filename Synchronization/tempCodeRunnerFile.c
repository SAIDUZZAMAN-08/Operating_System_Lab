#include <iostream>
// #include <thread>
// #include <mutex>
// #include <chrono>
// using namespace std;

// int sv = 1;     // shared variable
// mutex mtx;      // mutex for synchronization

// void fun1(){
//     lock_guard<mutex>lock(mtx);

//     int x=sv;

//     cout << "Thread 1 reads the value as " << x << endl;
//     x++;
//     cout << "Local updation by Thread 1: " << x << endl;

//     this_thread::sleep_for(chrono::seconds(1));  // simulate delay

//     sv = x;
//     cout << "Value of shared variable updated by Thread 1 is: " << sv << endl;
// }

// void fun2(){
//     lock_guard<mutex>lock(mtx);

//     int y=sv;

//     cout << "Thread 2 reads the value as " << y << endl;
//     y--;
//     cout << "Local updation by Thread 2: " << y << endl;

//     this_thread::sleep_for(chrono::seconds(1));  // simulate delay

//     sv = y;
//     cout << "Value of shared variable updated by Thread 1 is: " << sv << endl;
// }

// int main() {
//     thread t1(fun1);
//     thread t2(fun2);

//     t1.join();
//     t2.join();

//     cout << "Final value of shared variable is: " << sv << endl;
//     return 0;
// }
