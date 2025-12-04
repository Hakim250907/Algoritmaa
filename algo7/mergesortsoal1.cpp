#include <iostream>
#include <vector>
using namespace std;

// Fungsi untuk menggabungkan dua sub-array
void mergeArray(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; 
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    // Salin data ke array sementara L & R
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Proses merge (ascending)
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {   // ascending
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Sisa elemen L
    while (i < n1) {
        arr[k] = L[i];
        i++; k++;
    }

    // Sisa elemen R
    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
    }
}

// Fungsi rekursif merge sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        mergeArray(arr, left, mid, right);
    }
}

int main() {
    int n;

    // Input jumlah elemen
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    vector<int> arr(n);

    // Input nilai array
    cout << "Masukkan " << n << " nilai:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Proses merge sort
    mergeSort(arr, 0, n - 1);

    // Output hasil pengurutan
    cout << "\nArray setelah diurutkan (Ascending): ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
