/*

Find NO

● Read integer N, then read N strings.
○ Print only the strings (of 2 letters). These 2 letters must be letter ‘N’ and letter ‘O’ (regardless
of lower/upper case/order)
○ E.g. print “No”, “ON”, “no” but ignore e.g. “YEs”, “Noooo”
○ That is, the word of 2 letters only N and O
● Input
○ 9 Yss NO noOO oN Mostafa no nN oOOooo oO
● Output
○ NO oN no

*/

#include<iostream>
using namespace std;

int main() {
	
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        if(s == "no" || s == "No" || s == "NO" ||s == "nO" ||
        s == "on" ||s == "oN" ||s == "On" ||s == "ON")
        cout<<s<<" ";
    }
    
    return 0;
}
