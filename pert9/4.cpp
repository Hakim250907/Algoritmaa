#include <iostream>
using namespace std;

struct Customer {
    int nomor;
    int waktuPelayanan;
    Customer* next;
};

Customer* frontQueue = nullptr;
Customer* rearQueue = nullptr;
int nomorCounter = 1; // otomatis bertambah tiap tambah pelanggan

// Tambah pelanggan (enqueue)
void enqueue() {
    Customer* baru = new Customer();
    baru->nomor = nomorCounter++;
    cout << "Masukkan lama pelayanan (detik): ";
    cin >> baru->waktuPelayanan;
    baru->next = nullptr;

    if (rearQueue == nullptr) {
        frontQueue = rearQueue = baru;
    } else {
        rearQueue->next = baru;
        rearQueue = baru;
    }

    cout << "Pelanggan nomor " << baru->nomor << " berhasil ditambahkan ke antrian.\n";
}

// Layani pelanggan (dequeue)
void dequeue() {
    if (frontQueue == nullptr) {
        cout << "Antrian kosong, tidak ada pelanggan yang dilayani.\n";
        return;
    }

    Customer* hapus = frontQueue;
    cout << "Melayani pelanggan nomor " << hapus->nomor 
        << " (lama pelayanan: " << hapus->waktuPelayanan << " detik)...\n";

    frontQueue = frontQueue->next;
    if (frontQueue == nullptr) { 
        rearQueue = nullptr;
    }

    delete hapus;
}

// Tampilkan semua pelanggan yang menunggu
void tampilAntrian() {
    if (frontQueue == nullptr) {
        cout << "Tidak ada pelanggan dalam antrian.\n";
        return;
    }

    cout << "\n=== Daftar Antrian ===\n";
    Customer* temp = frontQueue;
    while (temp != nullptr) {
        cout << "- Pelanggan No." << temp->nomor 
            << " | Waktu Pelayanan: " << temp->waktuPelayanan << " detik\n";
        temp = temp->next;
    }
    cout << "=======================\n";
}

// Hitung jumlah antrian
void jumlahAntrian() {
    int count = 0;
    Customer* temp = frontQueue;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    cout << "Jumlah pelanggan dalam antrian: " << count << endl;
}

int main() {
    int pilihan;

    do {
        cout << "\n======== MENU ANTRIAN KASIR ========\n";
        cout << "1. Tambah pelanggan (Enqueue)\n";
        cout << "2. Layani pelanggan (Dequeue)\n";
        cout << "3. Tampilkan antrian\n";
        cout << "4. Tampilkan jumlah antrian\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: tampilAntrian(); break;
            case 4: jumlahAntrian(); break;
            case 5: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 5);

    return 0;
}