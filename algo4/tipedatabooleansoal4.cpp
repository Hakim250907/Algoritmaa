#include <iostream>
using namespace std;

int main() {
    int angka;
    bool isGenap;

    cout << "Masukkan angka: ";
    cin >> angka;

    // Menentukan apakah angka genap (sisa bagi 2 = 0)
    isGenap = (angka % 2 == 0);

    cout << "Apakah genap? " << (isGenap ? "true" : "false") << endl;

    return 0;
}
