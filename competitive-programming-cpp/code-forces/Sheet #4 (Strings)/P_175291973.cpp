#include<bits/stdc++.h>
using namespace std;
int main ()
{
    string s, res;
    int cntr = 0;
    getline(cin, s);
    for(int i =0; i< s.size(); i++){
        if(s[i] != 32 && s[i] != '!' && s[i] != '.' && s[i] != '?' && s[i] != ','){
            res += s[i];
        }
        if((s[i] == 32 || s[i] == '!' || s[i] == '?' || s[i] == '.' || s[i] == ',' || i == s.size()-1) && res.size() != 0){
            cntr++;
            res = "";
        }
    }
    cout<<cntr<<endl;
    return 0;
}