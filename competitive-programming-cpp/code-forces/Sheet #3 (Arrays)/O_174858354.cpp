#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long long n;
    cin>>n;
    long long arr[n];
    arr[0] = 0;
    arr[1] = 1;
    for(int i = 2; i <= n ;i++){
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    cout<<arr[n - 1]<<endl;
    return 0;
}