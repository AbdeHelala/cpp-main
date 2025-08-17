#include <bits/stdc++.h>
using namespace std;
int main()
{
   string num;
   cin>>num;
   int num1 = num[0] - '0';
   int num2 = num[1] - '0';
   if (num2 == 0){
    cout<<"YES"<<endl;
    return 0;
   }
   if (num1 % num2 == 0 || num2 % num1 == 0){
     cout<<"YES"<<endl;
     } else {
        cout<<"NO"<<endl;
        }
   
    return 0;
 
}