#include <iostream>
#include <string>
using namespace std;
 
int main() {
    int A, B;
    string S;
    cin >> A >> B >> S;
    int n = A + B + 1;
    
    bool flag = true;
    if (S[A] != '-' || n != S.size()) {
        flag = false;
    }
    for (int i = 0; i < n; i++) {
        if (i == A) {
            continue;
        }
        if (S[i] < '0' || S[i] > '9') {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}