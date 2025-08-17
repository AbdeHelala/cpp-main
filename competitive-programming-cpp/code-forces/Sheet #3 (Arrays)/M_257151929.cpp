using namespace std;
#include <iostream>
#include<bits/stdc++.h>
 
int main()
{
    int n, mn, mx, mn_idx = 0 , mx_idx = 0;
    cin>>n;
    int arr[n];
    
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    mn= arr[0];
    mx = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > mx){
            mx= arr[i];
            mx_idx = i;
        } else if(arr[i] < mn){
            mn = arr[i];
            mn_idx = i;
        }
       
    }
    arr[mn_idx] = mx;
    arr[mx_idx] = mn;
    for(int i = 0; i< n; i++){
        cout<<arr[i]<<" ";
    }
     
    return 0;
}