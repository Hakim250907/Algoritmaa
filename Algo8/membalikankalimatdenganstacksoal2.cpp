#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string kalimat;
    stack<char> tumpukan;
    cout << "Input  : ";
    getline(cin, kalimat); 
    for (int i = 0; i < kalimat.length(); i++) {
        tumpukan.push(kalimat[i]);
    }
    cout << "Output : ";
    while (!tumpukan.empty()) {
        cout << tumpukan.top();
        tumpukan.pop();
    }

    cout << endl;

    return 0;
}