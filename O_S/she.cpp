#include<bits/stdc++.h>
using namespace std;

struct P {
    int id, at, bt, pr, ct, wt, tat;
    bool done=false;
};


int main(){

    int n;
    cout<<"Process number "<<endl;
    cin>>n;

    vector<P>p(n);


    for(int i=0;i<n;i++){

        cin>>p[i].at>>p[i].bt>>p[i].pr;
        p[i].id=i;

    }

    int com=0,curr=0;
    double twt=0,ttat=0;


    while(com<n){
        int idx=-1,best=INT_MAX;

        for(int i=0;i<n;i++){
            if(!p[i].done && p[i].at<=curr && p[i].pr<best) {
                idx=i;
                best=p[i].pr;
            }
        }

        if(idx==-1){
            curr++;
            continue;
        }

        p[idx].ct=curr+p[idx].bt;
        p[idx].tat=p[idx].ct-p[idx].at;
        p[idx].wt=p[idx].tat-p[idx].bt;
        p[idx].done = true;
        com++;

        twt+=p[idx].wt;
        ttat+=p[idx].tat;
        curr=p[idx].ct;


    }

    vector<pair<double,double>>A(n);

    for(int i=0;i<n;i++){
        A[i].first=p[i].ct;
        A[i].second=p[i].id;
    }

    sort(A.begin(),A.end());

    cout<<"Sequence: ";

    for(int i=0;i<n;i++){
        cout<<A[i].second<<" ";
    }


    cout << "\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n";
    for (auto &x : p){
        cout << x.id << "\t" << x.at << "\t" << x.bt << "\t"
             << x.pr << "\t" << x.ct << "\t" << x.tat << "\t" << x.wt << "\n";
    }
    cout<<fixed<<setprecision(1);
    
    cout<<"Avg wt: "<<twt/n<<endl;
    cout<<"Avg tat: "<<ttat/n<<endl;


    return 0;
}