#include <bits/stdc++.h>
using namespace std;
int main() {
    string v;
    cin>>v;
    int s = v.size();
    for(int i = 0; i < s/2 ; i++){
        if(v[i] != v[s-i-1]){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    
    return 0;
}