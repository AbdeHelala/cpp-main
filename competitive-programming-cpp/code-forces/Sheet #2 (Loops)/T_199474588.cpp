#include <iostream>
#include <cmath>
using namespace std;
int main(void){
    int row;
    cin>>row;
    for(int i =1; i <= row; i++){
        for(int x = 1; x <= row-i; x++) cout<<" ";
        for(int x = 1; x <= i * 2 - 1; x++) cout<<"*";
        cout<<endl;
    }
    
return 0;
}