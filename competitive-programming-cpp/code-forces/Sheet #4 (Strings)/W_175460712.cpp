#include<bits/stdc++.h>
using namespace std;
int main() {
 string key = "PgEfTYaWGHjDAmxQqFLRpCJBownyUKZXkbvzIdshurMilNSVOtec#@_!=.+-*/";
string Original = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int flag;
    cin>>flag;
    string value;
    cin>>value;
    int size = value.size();
    int index;  
     if(flag == 1){
    for(int i =0; i< size; i++){
        for(int z =0; z < key.size(); z++){
            if(value[i] == Original[z]){
            index = z;
            break;
            }
        }
    cout<<key[index];
        
    }
    
    } else{
        for(int i =0; i< size; i++){
            for(int z = 0; z < key.size(); z++){
                if(value[i] == key[z]){
                index = z;
                break;
            }
            }
        
            cout<<Original[index];
        }
        
    } 
    
    
    return 0;
}