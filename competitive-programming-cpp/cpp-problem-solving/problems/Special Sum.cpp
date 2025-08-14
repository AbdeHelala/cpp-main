/*
                Special Sum
● Read T for number of test cases. For each test case read integer N. Then
read N integers a, b, c, ..... and compute the sum of:
○ (a, b*b, c*c*c, d*d*d*d, e*e*e*e*e......)
○ That is the k-th number is repeated k times
● Input:
○ 2
○ 3 5 7 2
○ 4 1 2 3 4
● Output
○ 62 [as (5 + 7*7 + 2*2*2) = 62]
○ 288 [as (1+2*2+3*3*3+4*4*4*4) = 288]
*/
#include<iostream>
using namespace std;

int main() {
	
    int t;
    cin>>t;
  /*
	 * We need 3 nested loops
	 * loop over test cases
	 * 	loop over reading numbers
	 * 	  loop to repeat the number K times (multiplication)
	 */
    while(t--){
        int n;
        cin>>n; // n = 3
        int n_cnt = 1;
        int sum = 0;
        while(n_cnt <= n){ // 3 <= 3
            int N ; // 2
            cin>>N;
            int cnt = n_cnt; // 3
            int res = 1;
            
            while(cnt > 0)
                res *= N, cnt--; // 2 * 2 * 2 = 8
            sum +=res ; //54 + 8 
            n_cnt++; //4
               
            
    
        }
         cout<<sum<<endl;

    }
    
    
    
    
    return 0;
}
