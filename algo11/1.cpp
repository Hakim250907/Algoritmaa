#include <iostream>
using namespace std;

int main() {
    int n;
    long long hasil = 1;

    cout << "Masukkan n: ";
    cin >> n;

    // proses faktorial menggunakan looping (iteratif)
    for (int i = 1; i <= n; i++) {
        hasil = hasil * i;
    }

    cout << n << "! = " << hasil << endl;

    return 0;
}
