#include<bits/stdc++.h>
using namespace std;
int main() {
   
   double n1, n2, n3;
   cin>>n1>>n2>>n3;
   if(n1 + n2 > n3 && n1 +n3 > n2 && n3 + n2 > n1){
       double sum = n1 +n2 +n3;
       cout<<"Valid"<<endl;
       cout<<fixed<<setprecision(6)<<sqrt((sum/2) * (sum/2 - n1) * (sum/2 - n2)* (sum/2 - n3))<<endl;
   } else {
       cout<<"Invalid"<<endl;
   }
    return 0;
}