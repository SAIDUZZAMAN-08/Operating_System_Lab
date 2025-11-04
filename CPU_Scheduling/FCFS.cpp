#include<bits/stdc++.h>
using namespace std;

struct process{

    int pid;
    int at;
    int bt;
    int ct;
    int wt;
    int tat;

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

    sort(p.begin(), p.end(), [](process a, process b) {
        return a.at < b.at;
    });

    int curr=0,twt=0,ttt=0;

    for(int i=0;i<n;i++){
        if(curr<p[i].at) curr=p[i].at;

        p[i].ct=curr+p[i].bt;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;

        twt+=p[i].at;
        ttt+=p[i].tat;

        curr=p[i].ct;

    }

    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &pr : p)
        cout << pr.pid << "\t" << pr.at << "\t" << pr.bt << "\t"
             << pr.ct << "\t" << pr.tat << "\t" << pr.wt << "\n";

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time = " << twt / n;
    cout << "\nAverage Turnaround Time = " << ttt / n << endl;



    return 0;
}