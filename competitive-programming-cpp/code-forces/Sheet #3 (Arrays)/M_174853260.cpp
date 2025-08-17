#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    int arr[n], mx, mn;
    for(int i =0; i < n; i++)
        cin>>arr[i];
        mx=*max_element(arr, arr + n);
        mn=*min_element(arr, arr + n);
        for(int i =0; i < n; i++){
            if(arr[i] == mx)
            cout<<mn<<" ";
            else if (arr[i] == mn)
            cout<<mx<<" ";
            else
            cout<<arr[i]<<" ";
        }
    
    return 0;
}