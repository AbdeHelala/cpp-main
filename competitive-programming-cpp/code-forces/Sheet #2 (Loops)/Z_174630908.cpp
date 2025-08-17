#include <bits/stdc++.h>
using namespace std;
 
int main()
{   
    int a, b, C = 0;
    cin>>a>>b;
    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= a; j++){
            int z = b - i - j;
            if(z >= 0 && z<= a){
                C++;
            }
        }
    }
    cout<<C<<endl;
    return 0;
}