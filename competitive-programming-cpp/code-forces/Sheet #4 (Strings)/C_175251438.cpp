#include <bits/stdc++.h>
using namespace std;
int main() {
  string v1, v2;
  cin>>v1>>v2;
  int s1 =v1.size(), s2 = v2.size(), s = min(s1, s2);
  int flag =0;
  for(int i =0; i < s; i++){
      if(v1[i] < v2[i]){
          cout<<v1<<endl;
          flag =0;
          break;
      } else if(v2[i] < v1[i]){
          cout<<v2<<endl;
          flag =0;
          break;
      } else{
          flag = -1;
      }
  }
  if(flag == -1){
      if(s1 > s2){
          cout<<v2<<endl;
      } else{
          cout<<v1<<endl;
      }
  }
  return 0;
}