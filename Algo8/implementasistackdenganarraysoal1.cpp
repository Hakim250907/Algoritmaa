#include <iostream>
using namespace std;

struct Stack {
    int *data;
    int top;
    int capacity;
};


void initStack(Stack &s, int size) {
    s.capacity = size;
    s.data = new int[size];
    s.top = -1;
}

bool isEmpty(Stack &s) {
    return s.top == -1;
}

bool isFull(Stack &s) {
    return s.top == s.capacity - 1;
}

void push(Stack &s, int value) {
    if (isFull(s)) {
        cout << "[Error] Stack Penuh! Tidak bisa menambahkan " << value << endl;
    } else {
        s.top++;
        s.data[s.top] = value;
        cout << "[Success] " << value << " berhasil ditambahkan." << endl;
    }
}

void pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "[Error] Stack Kosong! Tidak ada yang bisa dihapus." << endl;
    } else {
        cout << "[Success] Data " << s.data[s.top] << " berhasil dihapus." << endl;
        s.top--;
    }
}

void peek(Stack &s) {
    if (isEmpty(s)) {
        cout << "[Info] Stack Kosong." << endl;
    } else {
        cout << "Elemen teratas: " << s.data[s.top] << endl;
    }
}

void size(Stack &s) {
    cout << "Jumlah elemen: " << s.top + 1 << " / " << s.capacity << endl;
}

int main() {
    Stack myStack;
    int n, pilihan, value;

    cout << "--- PROGRAM IMPLEMENTASI STACK ---" << endl;
    cout << "Masukkan kapasitas maksimal stack: ";
    cin >> n;

    initStack(myStack, n);

    do {
        cout << "\n--- MENU STACK ---" << endl;
        cout << "1. Push (Tambah Data)" << endl;
        cout << "2. Pop (Hapus Data)" << endl;
        cout << "3. Peek (Lihat Data Atas)" << endl;
        cout << "4. IsEmpty (Cek Kosong)" << endl;
        cout << "5. Size (Jumlah Data)" << endl;
        cout << "6. Exit" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        cout << "------------------" << endl;

        switch (pilihan) {
            case 1:
                cout << "Masukkan angka: ";
                cin >> value;
                push(myStack, value);
                break;
            case 2:
                pop(myStack);
                break;
            case 3:
                peek(myStack);
                break;
            case 4:
                if (isEmpty(myStack)) 
                    cout << "Status: Stack Kosong." << endl;
                else 
                    cout << "Status: Stack Terisi." << endl;
                break;
            case 5:
                size(myStack);
                break;
            case 6:
                cout << "Keluar dari program..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 6);
    delete[] myStack.data;
    
    return 0;
}