#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
    string input;
    cin>> input;
    int a = 0;
    int b = 0;
    char op = '\0';
    int op_index = -1;
 
    for (int i = 0; i < input.length(); i++) {
        char c = input[i];
        if (!isdigit(c)) {
            op = c;
            op_index = i;
            break;
        }
    }
 
    for (int i = 0; i < op_index; i++) {
        char c = input[i];
        if (isdigit(c)) {
            a = a * 10 + (c - '0');
        }
    }
 
    for (int i = op_index + 1; i < input.length(); i++) {
        char c = input[i];
        if (isdigit(c)) {
            b = b * 10 + (c - '0');
        }
    }
 
    switch (op) {
        case '+':
            cout << a + b << endl;
            break;
        case '-':
            cout << a - b << endl;
            break;
        case '*':
            cout << a * b << endl;
            break;
        case '/':
            cout << a / b << endl;
            break;
        default:
            cout << "Invalid operator" << endl;
            break;
    }
 
    return 0;
}