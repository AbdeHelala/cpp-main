#include <iostream>
#include <string>
using namespace std;
 
bool isPalindrome(string s) {
    int i = 0, j = s.length() - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
 
int main() {
    string n;
    cin >> n;
 
    // Reverse N and remove leading zeros
    string revN = "";
    bool leadingZero = true;
    for (int i = n.length() - 1; i >= 0; i--) {
        if (n[i] != '0') {
            leadingZero = false;
        }
        if (!leadingZero) {
            revN += n[i];
        }
    }
 
    // Print N in reverse order without leading zeroes
    cout << revN << endl;
 
    // Check if N is a palindrome
    if (isPalindrome(n)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
 
    return 0;
}