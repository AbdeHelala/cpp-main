#include <iostream>
#include <cmath>
using namespace std;
int main(void){
    int a, b, tmp, sum = 0;
    
    while(true){
        cin>>a>>b;
        if(a <= 0 || b <=0){
            return 0;
        }
        if(a > b){
            tmp = a;
            a = b;
            b = tmp;
        }
        for(int i = a; i <= b; i++){
            sum += i;
            cout<<i<<" ";
        }
        cout<<"sum ="<<sum<<endl;
        sum = 0;
        
    }
    
return 0;
}