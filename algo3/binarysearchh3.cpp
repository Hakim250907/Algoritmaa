#include <iostream>
using namespace std;

int main() {
    int data[7] = {1, 3, 5, 7, 9, 11, 13};
    int kiri = 0, kanan = 6, tengah;
    int cari;
    bool ditemukan = false;

    cout << "Masukkan angka yang ingin dicari: ";
    cin >> cari;

    // Proses Binary Search
    while (kiri <= kanan) {
        tengah = (kiri + kanan) / 2;

        if (data[tengah] == cari) {
            cout << "Data ditemukan pada indeks ke-" << tengah << endl;
            ditemukan = true;
            break;
        } 
        else if (data[tengah] < cari) {
            kiri = tengah + 1;
        } 
        else {
            kanan = tengah - 1;
        }
    }

    if (!ditemukan) {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}
