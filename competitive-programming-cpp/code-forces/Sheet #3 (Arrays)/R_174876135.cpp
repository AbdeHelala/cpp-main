#include <bits/stdc++.h>
using namespace std;
 
int main()
{
   
    int n;
    cin>>n;
    int arr1[n];
    int arr2[n];
    for(int i = 0; i< n; i++)
    {
        cin>>arr1[i];
    } sort(arr1, arr1+n);
    for(int i =0;i<n; i++){
        cin>>arr2[i];
    } sort(arr2, arr2+n);
    int flag = 1;
    for(int i=0; i<n; i++)
    {
        if(arr1[i] != arr2[i])
        {
            flag = 0;
            break;
        }
            
        
    } 
    if(flag == 0)
    {
        cout<<"no"<<endl;
    } 
    else
    {
        cout<<"yes"<<endl;
    }
    return 0;
}