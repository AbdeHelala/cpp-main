#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int main() {
    long long num;
    cin>>num;
    int flag = 0;
    for(int i =2; i <= num/2; i++){
        int cntr = 0;
        while(num%i==0){
            cntr++;
            num /= i;
            
        }
        if(cntr > 0&& flag > 0){
            cout<<"*";
        }
        if(cntr > 0){
                cout<<"("<<i<<"^"<<cntr<<")";
                flag = 1;
        }
        if(num == 1 ){
            break;
        }
    }
    if(num > 1 && flag){
        cout<<"*";
    }
    if(num > 1){
        cout<<"("<<num<<"^"<<1<<")";
    }
    return 0;
}