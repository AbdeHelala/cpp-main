#include <iostream>
 
using namespace std;
 
int main()
{
    long long num1, num2, num3, num4;
    cin>>num1>>num2>>num3>>num4;
 
    int newInt1 = num1 % 100;
    int newInt2 = num2 % 100;
    int newInt3 = num3 % 100;
    int newInt4 = num4 % 100;
    
    int result = (newInt1 * newInt2 * newInt3 * newInt4);
        if(result % 100 <= 9){
        cout<<"0"<<result % 100<<endl;
        } else {
            cout<<result % 100<<endl;
     
 }
    
   
   
    return 0;
}