/*

Reverse number

● Read an integer N, then find its reverse integer R
○ Print R R*3
● input ⇒ Output
○ 123 ⇒ 321 963

*/
#include<iostream>
using namespace std;

int main() {
	
    int n;
    cin>>n;
    int last_digit;
    int  num= 0;
    while(n){
        last_digit = n % 10;
        n = n /10;
        num = num * 10 + last_digit; 
    }
    cout<<num<<" "<<num * 3<<endl;
    return 0;
}

