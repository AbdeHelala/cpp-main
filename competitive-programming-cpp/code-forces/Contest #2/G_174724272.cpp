#include <bits/stdc++.h>
using namespace std;
int res[1000005];
 
int main(){
 
 
   long long counter;
   cin>>counter;
    long long  c =0;
   for (int i = 0; i < counter; i++){
       long long num1, num2;
       cin>>num1>>num2;
       if(num1*(num1+1)/2 < num2){
           cout<<-1;
       } else {
           long long sum = 0;
          
           for(int z = num1; z >= 1; z--){
               if(sum +z <= num2){
                   sum+=z;
                   res[c] = z;
                   c++;
                   
               }
               if(sum == num2){
                   break;
               }
           }
           
       }
       for(int x =0; x<c;x++){
           cout<<res[x]<<" ";
       }
       cout<<endl;
       c = 0;
   }
    return 0;
}