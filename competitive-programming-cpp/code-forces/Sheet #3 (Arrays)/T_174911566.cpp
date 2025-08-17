#include<bits/stdc++.h>
using namespace std;
int main(){
        int n;
        cin>>n;
        int arr[n][n];
        long long m=0, s=0; 
        for(int i = 0; i<n;i++){
            for(int j = 0; j < n; j++){
                cin>>arr[i][j];
            }
        }
        for(int i =0 ; i <n; i++){
            for(int j =0; j < n; j++){
                if(i == j)
                m += arr[i][j];
                if((i+j)==(n-1))
                s += arr[i][j];
            }
        }
        cout<<abs(m-s)<<endl;
       return 0;
}