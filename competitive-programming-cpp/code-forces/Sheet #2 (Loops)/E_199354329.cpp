#include<bits/stdc++.h>
using namespace std;
 
int main() {
 int n, max = 0;
 cin>>n;
for(int i = 1; i <= n; i++){
    int a; 
    cin>>a;
    if(i == 1){
        max = a;
    } if(a > max){
        max = a;
    }
}
 cout<<max<<endl;
 
 
    return 0;
}