#include<bits/stdc++.h>
using namespace std;
const int s = 100001;
void print(int arr[s], int shift, int size){
    
    for(int i = shift ; i < size; i++){
        cout<<arr[i]<<" ";
    }
}
void print1(int arr[s], int shift){
    for(int i = 0; i < shift ; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int times, size;
    cin>>size>>times; 
    int arr[s];
    for(int i = 0; i < size; i++){
        cin>>arr[i];
    }
    int sh = times % size;
    print(arr, size -sh, size);
    print1(arr, size-sh);
    
}