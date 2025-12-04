#include <iostream>
using namespace std;

int main (){
    int a;
    int b;
    int c;
    double hasil;

    cout << "======================================"<<endl;
    cout << "ini adalah program operasi artimatika"<<endl;
    cout << "======================================"<<endl;

    cout << "silahkan pilih mau operasi apa : "<<endl;
    cout << "1. penjumlahan"<<endl;
    cout << "2. pengurangan"<<endl;
    cout << "3. perkalian"<<endl;
    cout << "4. pembagian"<<endl;

    cout << "masukan pilihan : ";
    cin >> a;

if (a == 1){
    cout << "masukan angka pertama : ";
    cin >> b;
    cout << "masukan angka kedua : ";
    cin >> c;
    hasil = b + c;
    cout << "hasilnya adalah : " << hasil <<endl;
}
else if (a == 2){
    cout << "masukan angka pertama : ";
    cin >> b;
    cout << "masukan angka kedua : ";
    cin >> c;
    hasil = b - c;
    cout << "hasilnya adalah : " << hasil <<endl;
}
else if (a == 3){
    cout << "masukan angka pertama : ";
    cin >> b;
    cout << "masukan angka kedua : ";
    cin >> c;
    hasil = b * c;
    cout << "hasilnya adalah : " << hasil <<endl;
}
else if (a == 4){
    cout << "masukan angka pertama : ";
    cin >> b;
    cout << "masukan angka kedua : ";
    cin >> c;
    hasil = b / c;
    cout << "hasilnya adalah : " << hasil <<endl;
}
else {
    cout << "pilihan tidak ada";
}

    cout << "======================================"<<endl;
    cout << "terimakasih sudah menggunakan program ini"<<endl;
    cout << "======================================"<<endl;

return 0;

}