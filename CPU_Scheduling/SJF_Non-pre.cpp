#include <bits/stdc++.h>
using namespace std;

struct process {
    int pid;
    int at;
    int bt;
    int ct;
    int wt;
    int tat;
    bool done = false;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<process> p(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter Arrival and Burst time for P" << i + 1 << ": ";
        cin >> p[i].at >> p[i].bt;
        p[i].pid = i + 1;
    }

    int com = 0, curr = 0;
    double twt = 0, ttt = 0;

    while (com < n) {
        int idx = -1;
        int minb = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!p[i].done && p[i].at <= curr && p[i].bt < minb) {
                idx = i;
                minb = p[i].bt;
            }
        }

        if (idx == -1) {  // CPU idle
            curr++;
            continue;
        }

        p[idx].ct = curr + p[idx].bt;
        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt = p[idx].tat - p[idx].bt;
        p[idx].done = true;
        com++;

        twt += p[idx].wt;
        ttt += p[idx].tat;
        curr = p[idx].ct;
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
