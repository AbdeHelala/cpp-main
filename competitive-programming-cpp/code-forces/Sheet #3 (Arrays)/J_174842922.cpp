#include <bits/stdc++.h>
using namespace std;
 
int main()
{
   int n, mn = 1e5, c = 0;
   cin>>n;
   int arr[n];
   for(int i = 0; i < n; i++){
       cin>>arr[i];
      
   } mn=*min_element(arr, arr + n );
        for(int i=0; i < n; i++){
           if(arr[i]==mn)
            c++;
       
   } if( c % 2 == 0 )
        cout<<"Unlucky"<<endl;
    else
        cout<<"Lucky"<<endl;
    
    return 0;
}