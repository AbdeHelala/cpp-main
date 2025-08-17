#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int a, b;
    cin>>a>>b;
    string s;
    cin>>s;
    if(s[a] != '-'){
        cout<<"No"<<endl;
        return 0;
    } else {
        for( int i = 0; i < s.size(); i++){
            if(i == a)
            continue ;
            else if(s[i]>='0'&&s[i]<='9');
            else {
                cout<<"No"<<endl;
                return 0;
            }
            
        }
        cout<<"Yes"<<endl;
    }
   
    return 0;
}