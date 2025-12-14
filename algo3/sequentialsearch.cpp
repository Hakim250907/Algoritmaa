#include <iostream>
using namespace std;

int main() {
    int data[5] = {5, 10, 15, 20, 25};
    int cari;
    bool ditemukan = false;

    cout << "Masukkan angka yang ingin dicari: ";
    cin >> cari;

    // Proses Sequential Search
    for (int i = 0; i < 5; i++) {
        if (data[i] == cari) {
            cout << "Data ditemukan pada indeks ke-" << i << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}
