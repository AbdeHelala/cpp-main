#include <bits/stdc++.h>
using namespace std;
int main()
{
    char letter;
    cin>> letter;
    int askichar = letter;
 
    if(askichar == 122){
        cout<<'a'<<endl;
        return 0;
    }
    int newchar = ++letter;
    char MynewASki = newchar;
    cout<<MynewASki<<endl;
 
 
 
 
    return 0;
 
}