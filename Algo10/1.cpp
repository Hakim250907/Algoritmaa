#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Process {
    string name;
    int at, bt;
    int rt;  // remaining time
    int ct, tat, wt, resp;
    bool started = false;
};

int main() {
    int n;
    cout << "Masukkan jumlah proses: ";
    cin >> n;

    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        cout << "\nProses " << i + 1 << ":\n";
        cout << "Nama proses     : "; 
        cin >> p[i].name;
        cout << "Arrival Time    : ";
        cin >> p[i].at;
        cout << "Burst Time      : ";
        cin >> p[i].bt;

        p[i].rt = p[i].bt;
        p[i].resp = -1;
    }

    int completed = 0, time = 0;
    vector<string> gantt;
    int lastProcess = -1;
    int preemptions = 0;

    while (completed < n) {
        int idx = -1;
        int mn = 1e9;

        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rt > 0) {
                if (p[i].rt < mn) {
                    mn = p[i].rt;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            if (lastProcess != idx && lastProcess != -1)
                preemptions++;

            if (!p[idx].started) {
                p[idx].resp = time - p[idx].at;
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

    // Hitung TAT, WT
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt  = p[i].tat - p[i].bt;
    }

    cout << "\n================ GANTT CHART ================\n";
    for (string &x : gantt) cout << x << " ";
    cout << "\n=============================================\n";

    cout << "\nJumlah preemption: " << preemptions << endl;

    cout << "\n================ HASIL AKHIR ================================\n";
    cout << left << setw(10) << "Proses" 
        << setw(10) << "AT"
        << setw(10) << "BT"
        << setw(10) << "CT"
        << setw(10) << "TAT"
        << setw(10) << "WT"
        << setw(10) << "RT"
        << endl;

    for (auto &x : p) {
        cout << left << setw(10) << x.name
            << setw(10) << x.at
            << setw(10) << x.bt
            << setw(10) << x.ct
            << setw(10) << x.tat
            << setw(10) << x.wt
            << setw(10) << x.resp
            << endl;
    }

    cout << "=============================================================\n";

    // Penjelasan Starvation
    cout << "\nPenjelasan Starvation:\n";
    cout << "- Pada SRTF, proses dengan burst time panjang dapat mengalami penundaan panjang\n";
    cout << "- Jika proses pendek terus berdatangan, proses panjang bisa 'kelaparan' (starvation)\n";
    cout << "- Ini terjadi karena CPU selalu memilih sisa waktu tersingkat\n";

    return 0;
}
