#include <bits/stdc++.h>
using namespace std;
int main() {
      int t;
      cin>>t;
      while(t--){
          int x, p =0;
          cin>>x;
          long long sum =0;
          while(x){
              int y = x%2;
              x/=2;
              if(y == 1){
                  sum+= pow(2,p);
                  p++;
              }
 
          }
          cout<<sum<<endl;
      }
 
 
    return 0;
}