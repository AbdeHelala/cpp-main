#include <bits/stdc++.h>
using namespace std;
void print(int num1){
        for(int i = 1; i <= num1; i++){
            if(i != 1){
            cout<<" ";    
            }
            
            cout<<i;
        }    
    
}
int main(){
    int num;
    cin>>num;
    print(num);
    
     return 0;
}