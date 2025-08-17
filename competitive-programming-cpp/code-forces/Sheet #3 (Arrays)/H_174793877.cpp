#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int size;
    cin>>size;
    int arr[size];
    
    for(int i =0; i < size; i++){
        cin>>arr[i];
    } for(int j= 1 ; j < size; j++){
        for(int z= 1; z < size ; z++){
        if(arr[z] < arr[z-1]){
            swap(arr[z],arr[z-1]); 
        }
    }
}
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}