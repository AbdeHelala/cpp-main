#include <iostream>
 
using namespace std;
 
int main() {
    int N;
    cin >> N;
 
    int num = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 3; j++) {
            if (j == 3) {
                cout << "PUM\n";
            } else {
                cout << num << " ";
                num++;
            }
        }
        num++;
    }
 
    return 0;
}