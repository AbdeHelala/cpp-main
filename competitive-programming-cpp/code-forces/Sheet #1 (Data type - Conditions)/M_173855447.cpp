#include <iostream>
using namespace std;
 
int main()
{
     char a;
     cin>>a;
     
     if(a >= 97 && a <= 122){
         cout<<"ALPHA"<<endl;
         cout<<"IS SMALL"<<endl;
     } else if (a >= 65 && a <= 90  ){
         cout<<"ALPHA"<<endl;
         cout<<"IS CAPITAL"<<endl;
     } else{
         cout<<"IS DIGIT"<<endl;
     }
     
     
     
     
     
     
     
     
    return 0;
}