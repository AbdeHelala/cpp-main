#include<bits/stdc++.h>
using namespace std;
long long sum(long long n){
    return n * (n+1) / 2;
}
int main(){
    long long n, b, c;
    cin>>n>>b>>c;
    if(n> b)
    swap(n, b);
    
    cout<<(sum(b/c) * c) - (sum((n -1) / c) * c);
}