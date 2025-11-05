#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <unistd.h>
using namespace std;

int sd;
int rc;
mutex mtx ,rmtx;

void reader(int id){
    for(int i=0;i<2;i++){
        mtx.lock();

        rc++;
        if(rc==1){
            rmtx.lock();
        }

        mtx.unlock();

         cout << "Reader " << id << " reads value: " << sd << endl;
         sleep(1);


        mtx.lock();

        rc--;
        if(rc==0){
            rmtx.unlock();
        }

        mtx.unlock();

        sleep(1);


    }

}

void writer(int id){
    for(int i=0;i<2;i++){
        rmtx.lock();

        sd++;
        cout << "Writer " << id << " updates value to: " << sd << endl;

        rmtx.unlock();

        sleep(1);
    }
}


int main(){
    
    thread w1(writer,1);
    thread r1(reader,1);
    thread r2(reader,2);
    thread w2(writer,2);
    thread r3(reader,3);

    r1.join();
    r2.join();
    w1.join();
    w2.join();
    r3.join();
}