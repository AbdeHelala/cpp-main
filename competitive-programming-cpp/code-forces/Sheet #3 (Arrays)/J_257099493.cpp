#include <iostream>
using namespace std;
int main()
{
    int n;
    int freq = 0;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    int min = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] == min){
            freq++;
        }
        if(arr[i] < min ){
            min = arr[i];
            freq = 1;
        }
       
    }
    if(freq % 2 != 0){
        cout<<"Lucky"<<endl;
    } else{
        cout<<"Unlucky"<<endl;
    }
    return 0;
}