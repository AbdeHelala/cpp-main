#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for( int i = 0; i < n; i++)
        cin>>arr[i];
        for( int  l=0; l < n; l++){
            for(int r = l; r<n; r++){
                  int mx = -1e5;
                for(int i = l; i<= r; i++){
                    if(arr[i]>mx)
                    mx = arr[i];
                }
                cout<<mx<<" ";
            }
        }
        cout<<endl;
    }
    
    return 0;
}