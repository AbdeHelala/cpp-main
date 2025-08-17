#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n1, n2, n3;
    cin>>n1>>n2>>n3;
    long long maxx = max(n1, n2);
    long long minn = min(n1, n2);
 
    long long result = 1;
    for(int i = minn; i <= maxx ;i++){
        result *= i;
        result %= n3;
    }
    cout<<result<<endl;
    return 0;
}