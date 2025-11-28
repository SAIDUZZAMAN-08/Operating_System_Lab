//pr.pre

#include <bits/stdc++.h>
using namespace std;

struct P {
    int id, at, bt, pr, ct, wt, tat, rem; 
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<P> p(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter AT, BT, PR for P" << i + 1 << ": ";
        cin >> p[i].at >> p[i].bt >> p[i].pr;
        p[i].id = i + 1;
        p[i].rem = p[i].bt; // initialize remaining time
    }

    int curr = 0, com = 0;
    double twt = 0, ttat = 0;

    while (com < n) {
        int idx = -1, best = INT_MAX;

        
        for (int i = 0; i < n; i++) {
            if (p[i].rem > 0 && p[i].at <= curr && p[i].pr < best) {
                best = p[i].pr;
                idx = i;
            }
        }

        if (idx == -1) { 
            curr++;
            continue;
        }

        
        p[idx].rem--;
        curr++;

        // If process finishes
        if (p[idx].rem == 0) {
            p[idx].ct = curr;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            twt += p[idx].wt;
            ttat += p[idx].tat;
            com++;
        }
    }

    cout << "\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n";
    for (auto &x : p)
        cout << x.id << "\t" << x.at << "\t" << x.bt << "\t"
             << x.pr << "\t" << x.ct << "\t" << x.tat << "\t" << x.wt << "\n";

    cout << fixed << setprecision(2);
    cout << "\nAvg WT = " << twt / n;
    cout << "\nAvg TAT = " << ttat / n << endl;

    return 0;
}
