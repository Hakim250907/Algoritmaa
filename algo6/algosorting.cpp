#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

// ==============================
//   BUBBLE SORT DESCENDING
// ==============================
void bubbleSortDescending(vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            // Descending → tukar jika elemen kiri < kanan
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

// ==============================
//   INSERTION SORT DESCENDING
// ==============================
void insertionSortDescending(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void printArray(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    cout << "==============================================\n";
    cout << "   Bubble Sort & Insertion Sort (Descending)\n";
    cout << "==============================================\n";

    // ---------- INPUT USER ----------
    int n;
    cout << "Masukkan jumlah data nilai ujian: ";
    cin >> n;

    vector<int> data(n);
    cout << "Masukkan " << n << " nilai:\n";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    cout << "\nData Awal: ";
    printArray(data);
    cout << "==============================================\n";

    // ---------- BUBBLE SORT ----------
    vector<int> bubbleData = data;

    auto startBubble = chrono::high_resolution_clock::now();
    bubbleSortDescending(bubbleData);
    auto endBubble = chrono::high_resolution_clock::now();

    auto timeBubble = chrono::duration_cast<chrono::microseconds>(endBubble - startBubble);

    cout << "Hasil Bubble Sort (Tertinggi ke Terendah):\n";
    printArray(bubbleData);
    cout << "Waktu Eksekusi Bubble Sort: " << timeBubble.count() << " mikrodetik\n";
    cout << "----------------------------------------------\n";

    // ---------- INSERTION SORT ----------
    vector<int> insertionData = data;

    auto startInsert = chrono::high_resolution_clock::now();
    insertionSortDescending(insertionData);
    auto endInsert = chrono::high_resolution_clock::now();

    auto timeInsert = chrono::duration_cast<chrono::microseconds>(endInsert - startInsert);

    cout << "Hasil Insertion Sort (Tertinggi ke Terendah):\n";
    printArray(insertionData);
    cout << "Waktu Eksekusi Insertion Sort: " << timeInsert.count() << " mikrodetik\n";
    cout << "==============================================\n";

    return 0;
}
