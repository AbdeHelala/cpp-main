#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
    int size;
    cin>>size;
    int arr[size];
    for(int i =0 ;i < size; i++){
        cin>>arr[i];
    } 
    sort(arr, arr+size);
    int temp =0, res =0, cntr =0;
    
    for(int i = 0; i < size ; i++){
        if(i == 0){
            temp = arr[i];
            res = 1;
        } else {
            if(temp == arr[i]){
                res++;
            } else if(temp+1 == arr[i]){
                cntr += res;
                temp = arr[i];
                res= 1;
            } else {
                res = 1;
                temp = arr[i];
            }
        }
    }
    cout<<cntr<<endl;
  return 0;
}