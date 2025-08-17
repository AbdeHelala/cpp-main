#include<bits/stdc++.h>
using namespace std;
const int s =1000;
int countNumber(int arr[s], int size){
    int counter =1;
    for(int i =1; i < size; i++){
        if(arr[i] != arr[i-1]){
            counter++;
        }
    }
    return counter;
}
int main(){
    int size;
    cin>>size;
    if(size == 0){
        cout<<0;
        return 0;
    }
    int arr[s];
    for(int i =0 ; i< size; i++ ){
        cin>>arr[i];
    }
    sort(arr, arr+size);
    cout<<countNumber(arr, size)<<endl;
}