#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    long long a, b, c, res=0;
    cin>>a>>b>>c;
    long long mn = min({a,b,c});
    res += mn;
    a -= mn;
    b -= mn;
    c -= mn;
    mn = min(a/2, c);
    res += mn;
    cout<<res<<endl;
    
    return 0;
 
}