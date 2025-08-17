#include <iostream>
 
using namespace std;
 
int main() {
    int size, indx, min;
    cin>>size;
    int arr[size];
    for(int i =0; i <size; i++)
    {
        cin>>arr[i];
    }
    
    for(int i =0; i <size; i++)
    {
 
        if(arr[i] < min || i == 0)
        {
           min = arr[i];
           indx = i;
        }
       
        
    }
    cout<<min<<" "<<indx + 1<<endl;
    
    return 0;
}