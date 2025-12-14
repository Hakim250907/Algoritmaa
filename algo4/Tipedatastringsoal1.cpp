#include <iostream>
#include <string>
using namespace std;

int main() {
    string namadepan, namabelakang, namasemua, pilihan;

    cout << "Masukkan nama depan: ";
    cin >> namadepan;

    cout << "Masukkan nama belakang: ";
    cin >> namabelakang;

    cout << "Ketik untuk gabung nama: ";
    cin >> pilihan;

    if (pilihan == "namasemua") {
        namasemua = namadepan + " " + namabelakang;
        cout << namasemua << endl;
    } else {
        cout << "Nama sebenarnya: " << namadepan << " " << namabelakang << endl;
    }
    return 0;
}