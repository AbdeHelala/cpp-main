#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int freq = 0, mn;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    mn = *min_element(arr, arr + n);
    for(int i = 0; i< n; i++){
        if(arr[i] == mn)
            freq++;
    }
    if(freq % 2 != 0){
        cout<<"Lucky"<<endl;
    } else{
        cout<<"Unlucky"<<endl;
    }
    return 0;
}