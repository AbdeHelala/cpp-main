#include <iostream>
 
using namespace std;
 
int main() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
 
    bool found = false;
 
    // Try freezing each operator and checking all possible combinations of the other two operators
    if (a + b - c == d || a + b * c == d || a * b + c == d || a - b + c == d || a - b * c == d || a * b - c == d) {
        found = true;
    } 
 
    // Output the result
    if (found) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
 
    return 0;
}