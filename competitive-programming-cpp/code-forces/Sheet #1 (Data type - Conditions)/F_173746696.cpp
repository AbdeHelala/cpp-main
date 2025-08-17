#include <iostream>
 
using namespace std;
int main()
{
    long long n1, n2;
    cin>>n1>>n2;
    int last_n1, last_n2;
    last_n1 = n1 % 10;
    last_n2 = n2 % 10;
    cout<<last_n1+last_n2<<endl;
    
    return 0;
}