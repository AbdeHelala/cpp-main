#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a, b, c, r;
    cin>>a >>b >>c >>r;
    long long m1 = (a * b) - c;
    long long m2 = (a * b) + c;
    long long m3 = a + (b - c);
    long long m4 = a + (b * c);
    long long m5 = (a - b) + c;
    long long m6 = a - (b * c);
    int flag = 0;
    if(m1 == r){
        cout<<"YES"<<endl;
        flag = 1;
 
    } else if (m2 == r){
        cout<<"YES"<<endl;
        flag = 1;
    } else if(m3 == r){
        cout<<"YES"<<endl;
        flag = 1;
    } else if(m4 == r){
        cout<<"YES"<<endl;
        flag = 1;
    } else if(m5 == r){
        cout<<"YES"<<endl;
        flag = 1;
    } else if(m6 == r){
    cout<<"YES"<<endl;
    flag = 1;
    } if (flag == 0){
    cout<<"NO"<<endl;
    }
 
    return 0;
 
}