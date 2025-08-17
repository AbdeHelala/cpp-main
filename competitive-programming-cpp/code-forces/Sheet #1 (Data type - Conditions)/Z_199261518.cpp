#include <iostream>
#include <cmath>
using namespace std;
 
int main() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    bool ab_greater_than_cd = false;
    if (b * log(a) > d * log(c)) {
        ab_greater_than_cd = true;
    }
    if (ab_greater_than_cd) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}