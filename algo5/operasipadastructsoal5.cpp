#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    float nilai_akhir;
};

int main() {
    const int JUMLAH = 5;
    Mahasiswa mhs[JUMLAH];
    float total = 0.0;

    // Input data
    for (int i = 0; i < JUMLAH; i++) {
        cout << "Mahasiswa ke-" << i + 1 << endl;

        cin.ignore(i == 0 ? 0 : 1, '\n'); // menghindari masalah input getline
        cout << "Nama         : ";
        getline(cin, mhs[i].nama);

        cout << "Nilai Akhir  : ";
        cin >> mhs[i].nilai_akhir;

        total += mhs[i].nilai_akhir;
        cout << endl;
    }

    // Hitung rata-rata
    float rata_rata = total / JUMLAH;

    // Output
    cout << "\n=====================================\n";
    cout << "Rata-rata nilai kelas: " << rata_rata << endl;
    cout << "=====================================\n";

    return 0;
}
