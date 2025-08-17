#include <bits/stdc++.h>
using namespace std;
int main() {
   int s;
   cin>>s;
   while(s--){
       string v;
       cin>>v;
       int size = v.size();
       if(size > 10){
           cout<<v[0]<<size-2<<v[size-1]<<endl;
       } else{
           cout<<v<<endl;
       }
   }
  return 0;
}