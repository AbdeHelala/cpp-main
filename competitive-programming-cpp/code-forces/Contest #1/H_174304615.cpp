#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    long double a, b, c;
    cin>>a>>b>>c;
    long double h = (a*b)/c;
    long long d = h;
    long double f = h - d;
    if(f > 0){
    cout<<"double"<<endl;
        return 0;
        }
    if(d <= 2147483647){
    cout<<"int"<<endl;
    } else{
    cout<<"long long"<<endl;
    }
    return 0;
 
}