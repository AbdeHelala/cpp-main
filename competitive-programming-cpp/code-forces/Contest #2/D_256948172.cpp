#include<iostream>
using namespace std;
 
int main()
{
    long long t,k,l,sum;
        cin>>t;
    for(long long i =0;i<t;i++){
            sum=0;
            cin>>k>>l;
        long long n1= k>l?k:l;
        long long n2= (k+l)-n1;
        sum=((n1-n2+1)*(n1+n2))/2;
            cout<<sum<<endl;
    }
    return 0;
}