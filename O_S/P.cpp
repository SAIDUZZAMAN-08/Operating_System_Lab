#include <iostream>
#include <thread>
#include <mutex>
#include <semaphore.h>
#include <vector>
#include <unistd.h>
#include <pthread.h>
#include <unistd.h>
using namespace std;
#define MAX_NUM 10
mutex mtx;
sem_t a;
sem_t b;

void *print_even(void *arg) {

for (int i = 0; i <= MAX_NUM; i += 2) {
sleep(2);
sem_wait(&a); 
printf("Even: %d\n", i);
sem_post(&b);
}

return NULL;
}

void *print_odd(void *arg) {
for (int i = 1; i <= MAX_NUM; i += 2) {
sleep(1); 
sem_wait(&b);
printf("Odd : %d\n", i);
sem_post(&a);
}
return NULL;
}
int main(void) {
sem_init(&a, 0, 1);
sem_init(&b, 0, 0);    

pthread_t t1, t2;
pthread_create(&t1, NULL, print_even, NULL);
pthread_create(&t2, NULL, print_odd, NULL);
pthread_join(t1, NULL);
pthread_join(t2, NULL);
return 0;
}
