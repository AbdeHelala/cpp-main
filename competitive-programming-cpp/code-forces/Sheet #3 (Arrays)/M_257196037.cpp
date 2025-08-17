using namespace std;
#include <iostream>
#include<bits/stdc++.h>
 
int main()
{
    int n, mn, mx;
    cin>>n;
    int arr[n];
    
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        
        if(i == 0){
            mn= arr[i];
            mx = arr[i];
        }
        if(arr[i] > mx){
            mx= arr[i];
        } 
        if(arr[i] < mn){
            mn = arr[i];
        }
    }
    
    
    for(int i = 0; i< n; i++){
        if(arr[i] == mn)
            cout<<mx<<" ";
        else if(arr[i] == mx)
            cout<<mn<<" ";
        else
            cout<<arr[i]<<" ";
    }
     
    return 0;
}