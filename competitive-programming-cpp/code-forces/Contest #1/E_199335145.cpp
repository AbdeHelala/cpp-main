#include <iostream>
#include <cmath>
 
using namespace std;
 
int main() {
    int a, b;
    cin >> a >> b;
 
    if (a == 0 && b == 0) {
        cout << "NO" << endl;
    } else {
        int diff = abs(a - b);
        if (diff >= 2) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
 
    return 0;
}