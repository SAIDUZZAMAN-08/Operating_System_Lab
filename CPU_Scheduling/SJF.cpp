#include<bits/stdc++.h>
using namespace std;

struct process{

    int pid;
    int at;
    int bt;
    int ct;
    int wt;
    int tat;
    bool done=false;

};

int main(){

    int n;
    cout<<"Enter number of process"<<endl;
    cin>>n;

    vector<process>p(n);

    for(int i=0;i<n;i++){

        cout << "Enter Arrival and Burst time for P" << i + 1 << ": ";
        cin>>p[i].at>>p[i].bt;
        p[i].pid=i+1;


    }

    int com=0,curr=0,twt=0,ttt=0;

    return 0;
}