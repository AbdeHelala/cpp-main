#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int num1, num2;
    while(cin>>num1>>num2){
        
          int mini, maxi, sum = 0;
        if(num1 <= 0 || num2 <=0){
            return 0;
        }
        
      
        if(num1 >= num2){
            maxi = num1;
            mini = num2;
        }
            else{
                maxi = num2;
                mini = num1;
            }
        
        for( int i = mini; i <= maxi; i++){
            cout<<i<<" ";
            sum += i;
        }
        cout<<"sum ="<<sum<<endl;
}
    return 0;
}