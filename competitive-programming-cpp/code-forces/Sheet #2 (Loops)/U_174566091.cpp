#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, a, b, sum = 0;
    cin>>n>>a>>b;
    for(int i = 1; i <= n; i++){
        int x = i;
        long long sm_d = 0;
        while(x){
            sm_d += x % 10;
            x/=10;
        }
        if(sm_d >= a && sm_d <= b)
            sum += i;
    }
    cout<<sum<<endl;
    return 0;
}