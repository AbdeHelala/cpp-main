#include <iostream>
#include <cmath>
using namespace std;
 
int main()
{
    long double num1, num2, num3, num4;
    cin>>num1>>num2>>num3>>num4;
 
    long double newInt1 = num2 * log(num1);
    long double newInt2 = num4 * log(num3);
    if(newInt1 > newInt2){
        cout<<"YES"<<endl;
    } else{
        cout<<"NO"<<endl;
    }
    
    
   
   
    return 0;
}