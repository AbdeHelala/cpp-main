#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int counter;
    cin>>counter;
    
    while(counter--){
        int num;
        cin>>num;
        if(num == 0){
            cout<<0<<" ";
        }
        else{    
        while(num){
            cout<<num%10<<" ";
            num = num /10;
        }
    } 
    cout<<endl;
        }
    
    return 0;
}