#include <bits/stdc++.h>
using namespace std;
int main() {
    string v;
    cin>>v;
    sort(v.begin(), v.end());
     for(int i = 0; i < v.size(); i++){
         char c = v[i];
         int cntr = 1;
         while(v[i] == v[++i]){
             cntr++;
         }
         i--;
         cout<<c<<" : "<<cntr<<endl;
     }
    return 0;
}