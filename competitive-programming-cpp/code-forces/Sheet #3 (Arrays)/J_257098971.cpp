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
    for(int i = 1; i < n; i++){
        if(arr[i] < min ){
            min = arr[i];
            
        }
    }
    for(int a = 0; a < n; a++){
        if(arr[a] == min){
            freq++;
        }
    }
    if(freq % 2 != 0){
        cout<<"Lucky"<<endl;
    } else{
        cout<<"Unlucky"<<endl;
    }
    return 0;
}