#include <iostream>
using namespace std;

int main() {
    int panjang, lebar, luas;

    cout << "Masukkan panjang: ";
    cin >> panjang;
    cout << "Masukkan lebar: ";
    cin >> lebar;

    luas = panjang * lebar;

    cout << "Luas Persegi Panjang = " << luas << endl;

    return 0;
}
