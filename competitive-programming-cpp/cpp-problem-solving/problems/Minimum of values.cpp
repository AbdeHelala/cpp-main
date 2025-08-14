/*
Minimum of values

● Read T for number of test cases. For each test case read integer N: number
of integers. For each test case, print the minimum of the N integers.
● Input
○ 2 6 10 50 20 70 30 4 3 10 5 30
○ Notice here we have 2 test cases
■ 6 10 50 20 70 30 4 [6 numbers to read]
■ 3 10 5 30

● Output
○ 4
○ 5

*/
#include<iostream>
using namespace std;

int main() {
	
    int t;
    cin>>t;
    int result = 0;
    while(t--){
        int n;
        cin>>n;
        int result = 0;
        while(n--){
            int x;
            cin>>x;
             
            if(result == 0)
                result = x;
            if(result > x)
                result = x;
            
            }
                cout<<result<<endl;

        }
        
    
            
    
    
    
    return 0;
}
