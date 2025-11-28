#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid;
    int at;     
    int bt;     
    int rt;     
    int ct;     
    int tat;    
    int wt;    
    bool done = false;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter Arrival and Burst time for P" << i + 1 << ": ";
        cin >> p[i].at >> p[i].bt;
        p[i].pid = i + 1;
        p[i].rt = p[i].bt; 
    }

    int completed = 0, current = 0;
    double totalWT = 0, totalTAT = 0;

    while (completed < n) {
        int idx = -1;
        int minRT = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (p[i].at <= current && !p[i].done && p[i].rt < minRT) {
                idx = i;
                minRT = p[i].rt;
            }
        }

        if (idx == -1) {
            current++;
            continue;
        }

        // Execute the selected process for 1 unit of time
        p[idx].rt--;
        current++;

        // If process finishes
        if (p[idx].rt == 0) {
            p[idx].done = true;
            p[idx].ct = current;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            totalWT += p[idx].wt;
            totalTAT += p[idx].tat;
            completed++;
        }
    }

    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &pr : p)
        cout << pr.pid << "\t" << pr.at << "\t" << pr.bt << "\t"
             << pr.ct << "\t" << pr.tat << "\t" << pr.wt << "\n";

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time = " << totalWT / n;
    cout << "\nAverage Turnaround Time = " << totalTAT / n << endl;

    return 0;
}
