#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int s;
    cin>>s;
    string v;
    cin>>v;
    long long sum =0;
    for(int i = 0; i < s ;i++)
    {
        sum += v[i] - '0';
    }
    cout<<sum<<endl;
    return 0;
}