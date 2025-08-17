#include <iostream>
#include <cmath>
using namespace std;
int main(void){
    int t, a, b, tmp;
    cin>>t;
    while(t--){
    int sum = 0;
        cin>>a>>b;
        if(a > b){
            tmp = b;
            b = a;
            a =tmp;
        }
        for(int i = a+1; i < b; i++){
            if(i % 2 != 0){
                sum += i;
            }
}
            cout<<sum<<endl;
 
}
return 0;
}