#include <iostream>         // library untuk input/output
using namespace std;        // supaya bisa pakai cout tanpa std::

int main() {
    // Array yang sudah terurut (syarat binary search adalah data harus terurut)
    int arr[] = {1, 3, 5, 7, 9, 11, 13};

    // menghitung jumlah elemen array
    int size = sizeof(arr) / sizeof(arr[0]);

    // input elemen yang ingin dicari dari user
    int x;
    cout << "Masukkan angka yang ingin dicari: ";
    cin >> x;

    // inisialisasi batas pencarian
    int low = 0;            // indeks awal
    int high = size - 1;    // indeks akhir

    // proses pencarian selama batas masih valid (low <= high)
    while (low <= high) {
        // mencari posisi tengah
        int mid = low + (high - low) / 2;
        
        // jika elemen tengah sama dengan yang dicari -> ketemu
        if (arr[mid] == x) {
            cout << "Elemen ditemukan di indeks: " << mid << endl;
            return 0; // program selesai
        }

        // jika elemen tengah lebih kecil dari x, cari di sisi kanan
        if (arr[mid] < x)
            low = mid + 1;
        // jika elemen tengah lebih besar dari x, cari di sisi kiri
        else
            high = mid - 1;
    }

    // jika perulangan selesai tanpa menemukan elemen
    cout << "Elemen tidak ditemukan" << endl;

    return 0; // program berakhir normal
}