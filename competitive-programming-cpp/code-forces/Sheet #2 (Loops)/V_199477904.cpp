#include <iostream>
 
using namespace std;
 
int main() {
    int N;
    cin >> N;
 
    int num = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 3; j++) {
            cout << num << " ";
            num++;
        }
        cout << "PUM\n";
        num++;
    }
 
    return 0;
}