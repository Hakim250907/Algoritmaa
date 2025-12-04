#include <iostream>
#include <iomanip>  // untuk setw()
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    const int JUMLAH = 3;
    Mahasiswa mhs[JUMLAH];

    // Input data mahasiswa
    for (int i = 0; i < JUMLAH; i++) {
        cout << "Data Mahasiswa ke-" << i + 1 << endl;

        cout << "Nama : ";
        cin.ignore(i == 0 ? 0 : 1, '\n');   // untuk mengatasi input getline
        getline(cin, mhs[i].nama);

        cout << "NIM  : ";
        getline(cin, mhs[i].nim);

        cout << "IPK  : ";
        cin >> mhs[i].ipk;

        cout << endl;
    }

    // Tampilkan dalam format tabel
    std::cout << "\n========= Data Mahasiswa Tersimpan ===========" << std::endl;
    cout << "\n==============================================\n";
    cout << left << setw(20) << "Nama"
        << setw(15) << "NIM"
        << "IPK" << endl;
    cout << "==============================================\n";

    for (int i = 0; i < JUMLAH; i++) {
        cout << left << setw(20) << mhs[i].nama
            << setw(15) << mhs[i].nim
            << fixed << setprecision(2) << mhs[i].ipk << endl;
    }

    cout << "==============================================\n";

    return 0;
}
