#include <bits/stdc++.h>
using namespace std;
 
int main()
{   
    int size;
    cin>>size;
    int arr[size];
    int mn, pos;
    for(int i = 0 ; i<size ; i++){
        cin>>arr[i];
    }
        mn = arr[0];
        pos = 1;
        for( int i = 1; i < size; i++){
        if(arr[i] < mn){
            mn = arr[i];
            pos = i+1;
        }
    }
    cout<<mn<<" "<<pos;
    return 0;
}