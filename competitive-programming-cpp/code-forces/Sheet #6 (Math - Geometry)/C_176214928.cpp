#include<bits/stdc++.h>
using namespace std;
long long sumOdd(long long num){
    long long res = (num +1 )/2;
    long long f_Res = res * res ;
    return f_Res;
}
long long sumEven(long long num ){
    long long res = (num*(num+1));
    return res;
}
int main(){
     int num1, num2;
     cin>>num1>>num2;
     if(num1 > num2)
     swap(num1, num2);
     long long sum_all =0, sum_even = 0, sum_odd = 0;
     
     sum_odd = sumOdd(num2) - sumOdd(num1 -1);
     sum_even = sumEven(num2/2) - sumEven((num1 -1)/2);
     sum_all = sum_odd + sum_even;
     cout<<sum_all<<endl<<sum_even<<endl<<sum_odd<<endl;
    }