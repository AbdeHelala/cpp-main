#include<iostream>
using namespace std;
 
int main()
{
    int cnt;
    cin>>cnt;
    for(int i = 1; i <= cnt; i++){
        if(cnt % i == 0){
            cout<<i<<endl;
        }
    
}
return 0;
}