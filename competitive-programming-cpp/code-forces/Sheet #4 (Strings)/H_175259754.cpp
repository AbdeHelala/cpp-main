#include <bits/stdc++.h>
using namespace std;
int main() {
   int c;
   cin>>c;
   while(c--){
       string s;
       cin>>s;
       int size = s.size();
       int flag =0;
       for(int i =0; i < size - 2 ; i++){
           if((s[i] == '0' && s[i+1] == '1'&& s[i+2] == '0') || (s[i] == '1' && s[i+1] == '0' &&s[i+2] == '1')){
               flag = 1;
               break;
           }
       }
       if(flag == 1){
           cout<<"Good"<<endl;
       } else{
           cout<<"Bad"<<endl;
       }
          
   }
   
  return 0;
}