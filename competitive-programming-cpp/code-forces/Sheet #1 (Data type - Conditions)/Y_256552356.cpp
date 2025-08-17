using namespace std;
#include <iostream>
// [0,25], (25,50], (50,75], (75,100]
int main()
{
    long long a, b, c, d;
    cin>>a>>b>>c>>d;
    a %= 100;
    b %= 100;
    c %= 100;
    d %= 100;
    long long reslut = a * b * c * d;
    long long last_digs = reslut % 100;
    if(last_digs <= 9)
        cout<<"0"<<last_digs<<endl;
    else
        cout<<last_digs<<endl;
    return 0;
}