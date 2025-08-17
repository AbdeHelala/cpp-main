#include<bits/stdc++.h>
using namespace std;
 
int main() {
 int cnt, sum_neg=0, sum_odd=0, sum_pos = 0, sum_even = 0;
 cin>>cnt;
 for(int i = 0; i < cnt; i++){
     int n;
     cin>>n;
     
    if(n < 0){
        sum_neg++;
    } 
    if(n > 0){
        sum_pos++;
    }
    if(n % 2 == 0){
        sum_even++;
    }
    if(n % 2 != 0){
        sum_odd++;
    }
 }
 cout<<"Even: "<<sum_even<<endl<<"Odd: "<<sum_odd<<endl<<"Positive: "<<sum_pos<<endl<<"Negative: "<<sum_neg<<endl;
 
    return 0;
}