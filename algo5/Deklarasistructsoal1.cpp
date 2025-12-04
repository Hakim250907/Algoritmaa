#include <iostream>
#include <string>
using namespace std;


struct mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    mahasiswa mhs1;
    mahasiswa mhs2;

    cout << "===================================" <<endl;
    mhs1.nama = "Hakim Nuzul Prasetya";
    mhs1.nim = "20250801020";
    mhs1.ipk = 3.70;

    cout << "nama: " << mhs1.nama << endl;
    cout << "nim: " << mhs1.nim << endl;
    cout << "ipk: " << mhs1.ipk << endl;

    cout << "===================================" <<endl;
    mhs2.nama = "kevin";
    mhs2.nim = "20250801018";
    mhs2.ipk = 3.55;

    cout << "nama: " << mhs2.nama << endl;
    cout << "nim: " << mhs2.nim << endl;
    cout << "ipk: " << mhs2.ipk << endl;

    return 0;
}