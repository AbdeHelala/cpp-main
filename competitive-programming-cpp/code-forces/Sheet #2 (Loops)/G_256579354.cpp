using namespace std;
#include <cmath>
#include <iostream>
 
int main()
{
    
   int n;
   cin>>n;
   while(n--){
       int x;
       cin>>x;
       long long reslut = 1;
       for(int i = 1; i <= x; i++){
           reslut *= i;
       }
       cout<<reslut<<endl;
   }
 
    return 0;
}