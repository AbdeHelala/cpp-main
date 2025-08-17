#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
    int line;
    cin>>line;
    int v;
    for(int i =0; i < line; i++){
        v = 1;
        for(int z = 0; z <= i; z++){
            cout<<v<<" ";
            v = v *(i - z) / (z +1);
        }
        cout<<endl;
    }
    
       return 0;
}