#include <bits/stdc++.h>
using namespace std;
int main() {
    string w1, w2;
    cin>>w1>>w2;
    cout<<w1.size()<<" "<<w2.size()<<endl;
    string full = w1+w2;
    cout<<full<<endl;
    char temp = w1[0];
    w1[0] = w2[0];
    w2[0] = temp;
    cout<<w1<<" "<<w2<<endl;
  return 0;
}