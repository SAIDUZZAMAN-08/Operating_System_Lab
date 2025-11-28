#include <bits/stdc++.h>
using namespace std;

struct P {
    int id, at, bt, rem, ct, wt, tat;
};

int main() {
    int n, tq;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<P> p(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter AT and BT for P" << i + 1 << ": ";
        cin >> p[i].at >> p[i].bt;
        p[i].id = i + 1;
        p[i].rem = p[i].bt;
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;

    queue<int> q;
    vector<bool> inq(n, false);
    int curr = 0, com = 0;
    double twt = 0, ttat = 0;

    while (com < n) {
        // Add newly arrived processes
        for (int i = 0; i < n; i++) {
            if (!inq[i] && p[i].at <= curr && p[i].rem > 0) {
                q.push(i);
                inq[i] = true;
            }
        }

        if (q.empty()) {
            curr++;
            continue;
        }

        int idx = q.front();
        q.pop();

        int exec = min(tq, p[idx].rem);
        p[idx].rem -= exec;
        curr += exec;

        // Add new arrivals during execution
        for (int i = 0; i < n; i++) {
            if (!inq[i] && p[i].at <= curr && p[i].rem > 0) {
                q.push(i);
                inq[i] = true;
            }
        }

        if (p[idx].rem == 0) {
            p[idx].ct = curr;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            com++;
            twt += p[idx].wt;
            ttat += p[idx].tat;
        } else {
            q.push(idx);
        }
    }

    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &x : p)
        cout << x.id << "\t" << x.at << "\t" << x.bt << "\t"
             << x.ct << "\t" << x.tat << "\t" << x.wt << "\n";

    cout << fixed << setprecision(2);
    cout << "\nAvg WT = " << twt / n;
    cout << "\nAvg TAT = " << ttat / n << endl;

    return 0;
}
