#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isPair(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

bool cekValiditas(string ekspresi) {
    stack<char> tumpukan;

    for (int i = 0; i < ekspresi.length(); i++) {
        char kar = ekspresi[i];
        if (kar == '(' || kar == '{' || kar == '[') {
            tumpukan.push(kar);
        }
        else if (kar == ')' || kar == '}' || kar == ']') {
            if (tumpukan.empty()) {
                return false;
            }
            if (isPair(tumpukan.top(), kar)) {
                tumpukan.pop();
            } else {
                return false; // Jika tidak cocok (misal top '(' tapi ketemu ']')
            }
        }
    }

    // 3. Cek Akhir: Stack harus kosong
    // Jika masih ada sisa, berarti ada kurung buka yang tidak ditutup
    return tumpukan.empty();
}

int main() {
    string input;

    cout << "--- Cek Validitas Kurung ---" << endl;
    cout << "Input  : ";
    getline(cin, input); // Menggunakan getline agar spasi terbaca

    if (cekValiditas(input)) {
        cout << "Output : Valid" << endl;
    } else {
        cout << "Output : Tidak Valid" << endl;
    }

    return 0;
}