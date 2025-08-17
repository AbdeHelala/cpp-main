#include <iostream>
 
using namespace std;
 
int main() {
    int size, indx, min;
    cin>>size;
    int arr[size];
    for(int i =0; i <size; i++){
        cin>>arr[i];
    }
    min = arr[0];
    indx = 1;
    for(int i =1; i <size; i++){
 
        if(arr[i] < min){
           min = arr[i];
           indx = i + 1;
        }
       
        
    }
    cout<<min<<" "<<indx<<endl;
    
    return 0;
}