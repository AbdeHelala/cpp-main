#include<bits/stdc++.h>
using namespace std;
int main(){
       int n, m;
       cin>>n>>m;
       int arr[n], freqArr[m+1]={};
       for(int i =0; i < n; i++){
           cin>>arr[i];
           int x =arr[i];
           freqArr[x]++;
       }
        for(int i =1; i< m+1; i++){
            cout<<freqArr[i]<<endl;
        }
       return 0;
}