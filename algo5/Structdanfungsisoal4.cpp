#include <iostream>
#include <string>
using namespace std;

struct Alamat {
    string kota;
    string provinsi;
};

struct Mahasiswa {
    string nama;
    string nim;
    Alamat alamat;
};

// Fungsi untuk menampilkan data mahasiswa
void tampilData(Mahasiswa m) {
    cout << "\n=== Data Mahasiswa ===\n";
    cout << "Nama      : " << m.nama << endl;
    cout << "NIM       : " << m.nim << endl;
    cout << "Kota      : " << m.alamat.kota << endl;
    cout << "Provinsi  : " << m.alamat.provinsi << endl;
}

int main() {
    Mahasiswa mhs;

    // Input data mahasiswa
    cout << "Masukkan Nama       : ";
    getline(cin, mhs.nama);

    cout << "Masukkan NIM        : ";
    getline(cin, mhs.nim);

    cout << "Masukkan Kota       : ";
    getline(cin, mhs.alamat.kota);

    cout << "Masukkan Provinsi   : ";
    getline(cin, mhs.alamat.provinsi);

    // Panggil fungsi untuk menampilkan data
    tampilData(mhs);

    return 0;
}
