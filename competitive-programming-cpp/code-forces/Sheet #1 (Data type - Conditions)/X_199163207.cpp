#include <iostream>
using namespace std;
 
int main() {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
 
    // check if the intervals intersect
    if (l2 <= r1 && l1 <= r2) {
        // find the boundaries of the intersection
        int left = max(l1, l2);
        int right = min(r1, r2);
        cout << left << " " << right << endl;
    } else {
        cout << "-1" << endl;
    }
 
    return 0;
}