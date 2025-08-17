#include<bits/stdc++.h>
#include<iostream>
using namespace std;
 
int main()
{
    int num, f = 1;
    cin>> num;
    for(int i = 2; i <= num /2 ; i++){
        if(num % i == 0){
            cout<<"NO"<<endl;
            f = 0;
            break;
        } 
        }
        
    if(f == 1){
    cout<<"YES"<<endl;    
    }
    
    
    
        return 0;
}