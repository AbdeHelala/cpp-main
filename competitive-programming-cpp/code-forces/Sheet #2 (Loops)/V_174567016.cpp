#include <bits/stdc++.h>
using namespace std;
int main() {
    int lines;
    cin>>lines;
    for(int i =1; i <= lines*4; i++ ){
        if(i % 4 == 0){
            cout<<"PUM"<<endl;
        } else{
            cout<<i<<" ";
        }
    }
 
    return 0;
}