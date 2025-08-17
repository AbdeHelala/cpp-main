#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int counter;
    cin>>counter;
    while(counter--){
        int  num1, num2, sum = 0;
        cin>>num1>>num2;
        if(num1 > num2)
        swap(num1,num2);
        for(int i = num1 +1 ; i <= num2 -1 ; i++){
            if(i % 2 != 0){
                sum+=i;
            }
            
        }
        cout<<sum<<endl;
 
    }
    return 0;
}