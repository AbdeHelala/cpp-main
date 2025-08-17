#include <iostream>
using namespace std;
 
int main()
{
     char a, resChar;
     cin>>a;
     int ask = a;
     if(a >= 97 && a <= 122){
         ask -= 32;
         resChar = ask;
         cout<<resChar<<endl;
     } else{
         ask += 32;
         resChar = ask;
         cout<<resChar<<endl;
     }
     
     
     
     
     
     
     
     
    return 0;
}