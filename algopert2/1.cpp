#include <iostream>
using namespace std;

int main() {
    int bilangan;

    cout << "Masukkan sebuah bilangan bulat: ";
    cin >> bilangan;

    if (bilangan % 2 == 0) {
        cout << "Bilangan Genap" << endl;
    } else {
        cout << "Bilangan Ganjil" << endl;
    }

    return 0;
}
