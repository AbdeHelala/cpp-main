#include<bits/stdc++.h>
using namespace std;
int print(int size){
    int counter = 0;
    for(int i =0; i< size; i++){
        int value; 
        cin>>value;
        if(value == 0){
            counter++;
        } else{
            cout<<value<<" ";
        }
    }
    return counter;
}
int main(){
    int size;
    cin>>size;
    int myCounter = print(size);
    for(int i =0; i < myCounter; i++){
        cout<<0<<" ";
        
    }
    
}