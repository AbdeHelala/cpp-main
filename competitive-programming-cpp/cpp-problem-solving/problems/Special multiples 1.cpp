/*
    Special multiples 1
● Read an integer N (1 <= 200): print all numbers that satisfy the following
property
○ Either number is divisible by 8
○ Or divisible by both 4 and 3
● Input: 100
● Output: 0 8 12 16 24 32 36 40 48 56 60 64 72 80 84 88 96
*/

#include<iostream>
using namespace std;

int main() {
	
	int n;
	cin>>n;
	int start = 0;
	while( start <= n){
	    if(start % 8 == 0 || ((start % 4 == 0) && (start % 3 == 0))){
	        cout<<start<<" ";
	    
	        
	    }
	    start++;
	    
	}
	
    return 0;
}
