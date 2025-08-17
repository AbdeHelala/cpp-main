#include <bits/stdc++.h>
using namespace std;
int main()
{
    double discount, price;
    cin>>discount>>price;
 
     double precentage = 100 - discount;
     double presResult = price / precentage;
     double Result = (discount * presResult) + price;
     cout<<Result<<endl;
 
}