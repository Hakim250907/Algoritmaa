#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    int arr[n];
    cout << "Masukkan elemen array (urut ascending):\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cout << "Masukkan nilai yang ingin dicari: ";
    cin >> x;

    int i = 0;
    bool found = false;

    while (i < n) {
        if (arr[i] == x) {
            found = true;
            break;
        } else if (arr[i] > x) {
            // karena array ascending, jika lebih besar langsung stop
            break;
        }
        i++;
    }

    if (found) {
        cout << "Elemen ditemukan di indeks: " << i << endl;
    } else {
        cout << "Elemen tidak ditemukan" << endl;
    }

    return 0;
}
