#include <iostream>
using namespace std;

int main() {
    int pilihan;

    cout << "Pilih jenis akun:\n";
    cout << "1. Dosen\n";
    cout << "2. Mahasiswa\n";
    cout << "Masukkan pilihan (1/2): ";
    cin >> pilihan;

    cout << endl;

    if (pilihan == 1) {
        cout << "Anda memilih akun: Dosen" << endl;
    }
    else if (pilihan == 2) {
        cout << "Anda memilih akun: Mahasiswa" << endl;
    }
    else {
        cout << "Pilihan tidak valid." << endl;
    }

    return 0;
}
