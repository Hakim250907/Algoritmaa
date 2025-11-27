#include <iostream>
using namespace std;

#define MAX 5 // Kapasitas maksimal queue

struct Queue {
    int data[MAX];
    int front;
    int rear;
    int count;
};

// Inisialisasi Queue
void init(Queue &q) {
    q.front = 0;
    q.rear = -1;
    q.count = 0;
}

// Mengecek Apakah Queue Penuh
bool isFull(Queue q) {
    return q.count == MAX;
}

// Mengecek Apakah Queue Kosong
bool isEmpty(Queue q) {
    return q.count == 0;
}

// Menambahkan elemen ke queue (Enqueue)
void enqueue(Queue &q, int value) {
    if (isFull(q)) {
        cout << "Queue penuh! Tidak bisa enqueue." << endl;
        return;
    }

    q.rear = (q.rear + 1) % MAX;
    q.data[q.rear] = value;
    q.count++;

    cout << "Enqueue: " << value << " Berhasil Dimasukan!" << endl;
}

// Menghapus elemen dari queue (Dequeue)
int dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue Kosong! Tidak bisa dequeue." << endl;
        return -1;
    }

    int value = q.data[q.front];
    q.front = (q.front + 1) % MAX;
    q.count--;

    // PERBAIKAN: Menambahkan spasi agar rapi (" berhasil")
    cout << "Dequeue: " << value << " berhasil dihapus!" << endl;
    return value;
}

// Melihat elemen terdepan
int frontValue(Queue q) {
    if (isEmpty(q)){
        cout << "Queue kosong!" << endl;
        return -1;
    }
    return q.data[q.front];
}

// Menampilkan isi queue
void display(Queue q) {
    if (isEmpty(q)) {
        cout << "Queue kosong!" << endl;
        return;
    }

    cout << "Isi Queue: ";
    int idx = q.front;

    for (int i = 0; i < q.count; i++) {
        cout << q.data[idx] << " ";
        idx = (idx + 1) % MAX;
    }

    cout << endl;
}

int main() {
    Queue q;
    init(q);

    int pilihan, nilai;

    do {
        cout << "\n=== PROGRAM QUEUE (ANTRIAN) ===" << endl;
        cout << "1. Enqueue (Tambah Data)" << endl;
        cout << "2. Dequeue (Hapus Data)" << endl;
        cout << "3. Lihat elemen depan" << endl;
        // PERBAIKAN: Menu 4 sebelumnya tertulis "Enqueue", seharusnya "Tampilkan"
        cout << "4. Tampilkan Isi Queue" << endl; 
        cout << "5. Keluar" << endl;
        cout << "Pilihan menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "Masukan nilai: ";
            cin >> nilai;
            enqueue(q, nilai);
            break;

        case 2:
            dequeue(q);
            break;

        case 3:
            nilai = frontValue(q);
            if (nilai != -1)
                cout << "Elemen Depan: " << nilai << endl;
            break;

        case 4:
            display(q); // Fungsi ini menampilkan input data yang ada di dalam antrian
            break;

        case 5:
            cout << "Program selesai. Terima Kasih." << endl;
            break;

        default:
            cout << "Pilihan tidak valid" << endl;
        }
    } while (pilihan != 5);

    return 0;
}