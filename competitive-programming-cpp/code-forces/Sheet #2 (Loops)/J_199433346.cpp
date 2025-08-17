#include <iostream>
using namespace std;
 
void printPrimes(int n) {
    for (int i = 2; i <= n; i++) {
        bool isPrime = true;
 
        // Check if i is prime
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
 
        // Output i if it is prime
        if (isPrime) {
            cout << i << " ";
        }
    }
    cout << endl;
}
 
int main() {
    int n;
    cin >> n;
 
    printPrimes(n);
 
    return 0;
}