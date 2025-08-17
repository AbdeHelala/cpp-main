#include <iostream>
 
using namespace std;
 
int main() {
    int size, indx = 0, min;
    cin>>size;
    int arr[size];// 1, 2, 3 
    for(int i =0; i <size; i++){
        cin>>arr[i];
    }
    min = arr[0]; // 1
    for(int i =1; i <size; i++){
 
        if(arr[i] < min){ // 2 < 1
           min = arr[i]; // 
           indx = i; // 
        }
       
        
    }
    cout<<min<<" "<<indx+1<<endl;
    
    return 0;
}