#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void mergeAscending(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

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

void mergeSortAscending(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSortAscending(arr, left, mid);
        mergeSortAscending(arr, mid + 1, right);
        mergeAscending(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr(10);
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100 + 1;
    }

    cout << "Bilangan sebelum diurutkan: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;
    mergeSortAscending(arr, 0, arr.size() - 1);
    cout << "Bilangan setelah diurutkan (Ascending): ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}