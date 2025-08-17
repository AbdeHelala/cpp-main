#include<bits/stdc++.h>
using namespace std;
 
int main() {
    
    int a, b, c;
    cin>>a;
     b = a / 10;
     c = a % 10;
     if(b == 0 || c == 0){
         cout<<"YES"<<endl;
         return 0;
     }
     if(b % c == 0 || c % b == 0){
         cout<<"YES"<<endl;
         
     } else{
         cout<<"NO"<<endl;
     }
    
 
    return 0;
}