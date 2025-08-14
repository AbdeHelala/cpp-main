/* 

    Special multiples 2
● Read an integer N (1 <= 30): Print the first N numbers that are
○ multiple of 3 but not multiple of 4
● Input: 11
● Output: 3 6 9 15 18 21 27 30 33 39 42
*/

#include<iostream>
using namespace std;

int main() {
	
    int n;
    cin>>n;
    int start = 1;
    int cnt = 0;
    while(true){
        if(start % 3 == 0 && !(start % 4 == 0) ){
            cout<<start<< " ";
                   cnt++;

        }
        start++; 
        if(cnt == n + 1)
        break;
    }
	
    return 0;
}
