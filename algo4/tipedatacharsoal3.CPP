#include <iostream>
using namespace std;

int main() {
    char huruf;

    // Input karakter
    cout << "Masukkan satu huruf: ";
    cin >> huruf;

    // Tampilkan huruf dan kode ASCII-nya
    cout << "Kode ASCII dari " << huruf << " adalah " << (int)huruf << endl;

    return 0;
}
