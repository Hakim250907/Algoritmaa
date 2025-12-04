#include <iostream>
#include <vector>
using namespace std;

// Fungsi untuk menggabungkan dua subarray secara descending
void mergeDescending(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Membuat sub-vektor sementara
    vector<int> L(n1);
    vector<int> R(n2);

    // Menyalin data ke sub-vektor
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Menggabungkan dua sub-vektor secara descending
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Menyalin sisa elemen (jika ada)
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Fungsi rekursif untuk Merge Sort
void mergeSortDescending(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        // Panggil rekursif untuk kedua bagian
        mergeSortDescending(arr, left, mid);
        mergeSortDescending(arr, mid + 1, right);

        // Gabungkan hasil pengurutan
        mergeDescending(arr, left, mid, right);
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Masukkan nilai-nilai array:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSortDescending(arr, 0, n - 1);

    cout << "Array setelah diurutkan (Descending): ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}