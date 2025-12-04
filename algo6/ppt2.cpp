#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) { 
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        cout << "Langkah " << i + 1 << ": ";
        for (int k = 0; k < n; k++)
            cout << arr[k] << " ";
        cout << endl;

        if (!swapped)
            break;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        if (maxIndex != i)
            swap(arr[i], arr[maxIndex]);

        cout << "Langkah " << i + 1 << ": ";
        for (int k = 0; k < n; k++)
            cout << arr[k] << " ";
        cout << endl;
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        cout << "Langkah " << i << ": ";
        for (int k = 0; k < n; k++)
            cout << arr[k] << " ";
        cout << endl;
    }
}

void tampilArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah siswa: ";
    cin >> n;

    int nilai[n];
    cout << "\nMasukkan nilai ujian siswa:\n";
    for (int i = 0; i < n; i++) {
        cout << "Nilai siswa ke-" << i + 1 << ": ";
        cin >> nilai[i];
    }

    int arrBubble[n], arrSelection[n], arrInsertion[n];
    for (int i = 0; i < n; i++)
        arrBubble[i] = arrSelection[i] = arrInsertion[i] = nilai[i];

    cout << "\nArray awal: ";
    tampilArray(nilai, n);

    cout << "\n=== Proses Bubble Sort (Descending) ===\n";
    auto start1 = high_resolution_clock::now();
    bubbleSort(arrBubble, n);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout << "Array setelah sorting (Bubble Sort): ";
    tampilArray(arrBubble, n);
    cout << "Waktu eksekusi: " << duration1.count() << " mikrodetik\n\n";

    cout << "=== Proses Selection Sort (Descending) ===\n";
    auto start2 = high_resolution_clock::now();
    selectionSort(arrSelection, n);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "Array setelah sorting (Selection Sort): ";
    tampilArray(arrSelection, n);
    cout << "Waktu eksekusi: " << duration2.count() << " mikrodetik\n\n";

    cout << "=== Proses Insertion Sort (Descending) ===\n";
    auto start3 = high_resolution_clock::now();
    insertionSort(arrInsertion, n);
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    cout << "Array setelah sorting (Insertion Sort): ";
    tampilArray(arrInsertion, n);
    cout << "Waktu eksekusi: " << duration3.count() << " mikrodetik\n\n";

    cout << "=== PERBANDINGAN WAKTU EKSEKUSI ===\n";
    cout << "Bubble Sort   : " << duration1.count() << " mikrodetik\n";
    cout << "Selection Sort: " << duration2.count() << " mikrodetik\n";
    cout << "Insertion Sort: " << duration3.count() << " mikrodetik\n";
    cout << "Kesimpulan: Waktu paling kecil menunjukkan algoritma paling cepat.\n";

    return 0;
}