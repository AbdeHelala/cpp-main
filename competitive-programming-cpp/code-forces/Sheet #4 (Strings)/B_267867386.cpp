#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
    string S;
    getline(cin, S);
    size_t index = S.find('\\');
    if (index != string::npos) {
        cout << S.substr(0, index) << endl;
    } else {
        cout << S << endl;
    }
    return 0;
}