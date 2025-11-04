#include<stdio.h>
#include<iostream>
#include<pthread.h>
using namespace std;

struct thread_data{

    int *arr;
    int start;
    int fact;
};

void*factorial(void*arg){

    thread_data *data=(thread_data*)arg;

    int n=data->arr[data->start];
    data->fact=1;
    
    for(int i=n;i>1;i--){
        data->fact*=i;
    }

    printf("Factorial of %d is: %d \n",n,data->fact);
    return NULL;
    
}

int main(){

    int arr[3]={3,4,5};

    // for(int i=0;i<3;i++){
    //     scanf("%d",&arr[i]);
    // }

    thread_data d1,d2,d3;
    d1={arr,0,1};
    d2={arr,1,1};
    d3={arr,2,1};

    pthread_t thread1,thread2,thread3;

    pthread_create(&thread1,NULL,factorial,(void*)&d1);
    pthread_create(&thread2,NULL,factorial,(void*)&d2);
    pthread_create(&thread3,NULL,factorial,(void*)&d3);

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    pthread_join(thread3,NULL);

    int t=d1.fact+ d2.fact+d3.fact;
    printf("The some of all factorial is: %d ",t);


}


