#include <iostream>
 
using namespace std;
 
int main() {
    int size, flag = 1;
    cin>>size;
    int arr[size];
    for(int i =0; i <size; i++)
    {
        cin>>arr[i];
    }
    
    for(int i =0; i < size / 2; i++){
        if(arr[i] != arr[size - 1 - i]){
            flag = 0;
        } 
    
    }
    if(flag){
        cout<<"YES"<<endl;
    } else{
        cout<<"NO"<<endl;
    }
    return 0;
}