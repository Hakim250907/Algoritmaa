#include <iostream>
using namespace std;

struct Pelanggan {
    int nomor;
    int lamaPelayanan;
    Pelanggan* next;
};

// Pointer depan & belakang queue
Pelanggan* frontQueue = nullptr;
Pelanggan* backQueue = nullptr;

// Cek kosong
bool isEmpty() {
    return frontQueue == nullptr;
}

// Enqueue (Tambah pelanggan)
void enqueue(int nomor, int lamaPelayanan) {
    Pelanggan* baru = new Pelanggan;
    baru->nomor = nomor;
    baru->lamaPelayanan = lamaPelayanan;
    baru->next = nullptr;

    if (isEmpty()) {
        frontQueue = backQueue = baru;
    } else {
        backQueue->next = baru;
        backQueue = baru;
    }
    cout << "Pelanggan " << nomor << " masuk antrian.\n";
}

// Dequeue (Layani pelanggan)
void dequeue() {
    if (isEmpty()) {
        cout << "Tidak ada pelanggan dalam antrian.\n";
        return;
    }

    Pelanggan* hapus = frontQueue;
    cout << "Melayani pelanggan nomor: " << hapus->nomor
        << " (Lama pelayanan: " << hapus->lamaPelayanan << " detik)\n";

    frontQueue = frontQueue->next;

    if (frontQueue == nullptr)
        backQueue = nullptr;

    delete hapus;
}

// Tampilkan pelanggan yang sedang menunggu
void tampilkanAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong.\n";
        return;
    }

    cout << "\nDaftar pelanggan menunggu:\n";
    Pelanggan* temp = frontQueue;
    while (temp != nullptr) {
        cout << "Nomor: " << temp->nomor
            << ", Lama pelayanan: " << temp->lamaPelayanan << " detik\n";
        temp = temp->next;
    }
    cout << endl;
}

// Hitung jumlah pelanggan
int jumlahAntrian() {
    int count = 0;
    Pelanggan* temp = frontQueue;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Main menu
int main() {
    int pilihan;
    int nomor = 1;

    do {
        cout << "\n=== SIMULASI ANTRIAN KASIR ===\n";
        cout << "1. Tambah pelanggan (enqueue)\n";
        cout << "2. Layani pelanggan (dequeue)\n";
        cout << "3. Tampilkan antrian\n";
        cout << "4. Tampilkan jumlah pelanggan\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                int lamaPelayanan;
                cout << "Masukkan lama pelayanan (detik): ";
                cin >> lamaPelayanan;
                enqueue(nomor++, lamaPelayanan);
                break;
            }

            case 2:
                dequeue();
                break;

            case 3:
                tampilkanAntrian();
                break;

            case 4:
                cout << "Jumlah pelanggan: " << jumlahAntrian() << endl;
                break;

            case 5:
                cout << "Keluar program...\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 5);

    return 0;
}
