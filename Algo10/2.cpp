#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Process {
    string name;
    int at, bt, priority;
    int rt;            // remaining time
    int ct, tat, wt, rtme;
    int originalPriority;
    bool started = false;
    int lastWaitStart; // waktu mulai menunggu
    int totalWait;     // total waktu menunggu untuk aging
};

int selectProcess(const vector<Process>& p, int time) {
    int idx = -1;
    int best = 1e9;

    for (int i = 0; i < p.size(); i++) {
        if (p[i].at <= time && p[i].rt > 0) {
            if (p[i].priority < best) {
                best = p[i].priority;
                idx = i;
            }
        }
    }
    return idx;
}

int main() {
    int n;
    cout << "Masukkan jumlah proses: ";
    cin >> n;

    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        cout << "\nProses " << i+1 << ":\n";
        cout << "Nama proses     : "; cin >> p[i].name;
        cout << "Arrival Time    : "; cin >> p[i].at;
        cout << "Burst Time      : "; cin >> p[i].bt;
        cout << "Priority        : "; cin >> p[i].priority;
        p[i].rt = p[i].bt;
        p[i].originalPriority = p[i].priority;
        p[i].lastWaitStart = p[i].at;
        p[i].totalWait = 0;
        p[i].rtme = -1; // response time awal
    }

    int completed = 0, time = 0;
    vector<string> gantt;
    int lastProcess = -1;
    int priorityChanges = 0;

    while (completed < n) {

        // Aging: proses yang sedang MENUNGGU
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rt > 0) {
                if (i != lastProcess) {
                    int waitDuration = time - p[i].lastWaitStart;
                    p[i].totalWait += waitDuration;

                    // Aging rule
                    if (p[i].totalWait >= 5) {
                        p[i].priority--;
                        if (p[i].priority < 1) p[i].priority = 1;
                        priorityChanges++;
                        p[i].totalWait = 0;
                    }

                    p[i].lastWaitStart = time;
                }
            }
        }

        int idx = selectProcess(p, time);

        if (idx != -1) {

            // Deteksi preemption
            if (lastProcess != idx && lastProcess != -1)
                gantt.push_back("|");

            // Response time
            if (!p[idx].started) {
                p[idx].rtme = time - p[idx].at;
                p[idx].started = true;
            }

            gantt.push_back(p[idx].name);
            p[idx].rt--;
            lastProcess = idx;

            if (p[idx].rt == 0) {
                p[idx].ct = time + 1;
                completed++;
            }

        } else {
            gantt.push_back("-");
        }

        time++;
    }

    // Hitung final metrics
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }

    cout << "\n================== GANTT CHART ==================\n";
    for (auto &x : gantt) cout << x << " ";
    cout << "\n=================================================\n";

    cout << "\nJumlah perubahan prioritas (aging): " << priorityChanges << endl;

    cout << "\n================== HASIL AKHIR ==================\n";
    cout << left << setw(10) << "Proses"
        << setw(10) << "AT"
        << setw(10) << "BT"
        << setw(12) << "PrioAwal"
        << setw(10) << "CT"
        << setw(10) << "TAT"
        << setw(10) << "WT"
        << setw(10) << "RT"
        << endl;

    for (auto &x : p) {
        cout << left << setw(10) << x.name
            << setw(10) << x.at
            << setw(10) << x.bt
            << setw(12) << x.originalPriority
            << setw(10) << x.ct
            << setw(10) << x.tat
            << setw(10) << x.wt
            << setw(10) << x.rtme
            << endl;
    }

    cout << "=================================================\n";

    cout << "\nSimulasi tanpa aging menunjukkan bahwa proses dengan priority tinggi namun burst besar\n"
        << "bisa tidak pernah dieksekusi jika proses kecil terus berdatangan → terjadi starvation.\n";

    return 0;
}
