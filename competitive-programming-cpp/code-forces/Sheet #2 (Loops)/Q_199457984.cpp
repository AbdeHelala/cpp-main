#include <iostream>
using namespace std;
 
int main() {
    int T;
    cin >> T;
 
    for (int i = 0; i < T; i++) {
        long long N;
        cin >> N;
 
        if (N == 0) {
            cout << "0" << endl;
        } else {
            while (N != 0) {
                int digit = N % 10;
                cout << digit << " ";
                N /= 10;
            }
            cout << endl;
        }
    }
 
    return 0;
}