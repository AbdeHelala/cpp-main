#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int counter, num1, num2;
  cin>>counter;
  while(counter--){
  cin>>num1>>num2;
  if(num1 == num2){
	cout<<"Square"<<endl;
  } else{
  	cout<<"Rectangle"<<endl;
    }
  }
  return 0;
}