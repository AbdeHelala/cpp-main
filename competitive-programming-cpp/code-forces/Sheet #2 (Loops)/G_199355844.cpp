#include <iostream>
#include <cmath>
using namespace std;
int main(void){
int n;
cin>>n;
 
for(int i=0;i<n;i++)
  {
    int x;
    long long result=1;
    cin>>x;
    for(int j=1;j<=x;j++)
      {
        result*=j;
      }
      cout<<result<<endl;
  }
 
}