#include <iostream>
#include <bitset>
 
using namespace std;
 
int countOnes(int n) {
    int count = 0;
    while (n) {
        count++;
        n &= (n - 1);
    }
    return count;
}
 
int main() {
    int T;
    cin >> T;
 
    while (T--) {
        int n;
        cin >> n;
 
        int ones = countOnes(n);
        int m = (1 << ones) - 1;
        cout << m << endl;
    }
 
    return 0;
}