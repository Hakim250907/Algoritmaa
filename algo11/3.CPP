#include <iostream>
using namespace std;

// Fungsi rekursif untuk menghitung faktorial
int faktorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * faktorial(n - 1);
}

int main() {
    int n;

    cout << "Masukkan n: ";
    cin >> n;

    // Menampilkan deret faktorial dari 1 sampai n
    for (int i = 1; i <= n; i++) {
        cout << i << "! = " << faktorial(i) << endl;
    }

    return 0;
}