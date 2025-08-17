#include <iostream>
#include <cmath>
using namespace std;
int main(void){
int A,B, temp, gcd;
cin>>A>>B;
if(A > B){
    temp = B;
    B = A;
    A = temp;
}
for(int i= 1;i<= B;i++)
  {
    if(A%i==0 && B % i == 0)
      {
        gcd = i;
  }
}
cout<<gcd<<endl;
return 0;
}