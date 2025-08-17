#include <iostream>
#include <vector>
using namespace std;
 
vector<int> getPrimes(int n) {
    vector<bool> isPrime(n+1, true);
    vector<int> primes;
 
    // Mark multiples of each prime as not prime
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = 2*i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
 
    return primes;
}
 
int main() {
    int n;
    cin >> n;
 
    vector<int> primes = getPrimes(n);
 
    // Output prime numbers
    for (int i = 0; i < primes.size(); i++) {
        cout << primes[i] << " ";
    }
    cout << endl;
 
    return 0;
}