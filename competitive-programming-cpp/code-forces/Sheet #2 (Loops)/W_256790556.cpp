#include <iostream>
 
using namespace std;
 
int main() {
    
    int lines;
    cin >> lines;
    int asterisk = 1;
    int space = lines - 1;
    for(int i = 1; i <= lines * 2; i++){
        for(int j = 1; j <= space; j++){
            cout<<" ";
        } for(int k = 1; k <= asterisk; k++){
            cout<<"*";
        } 
        cout<<endl;
        if(i < lines){
            asterisk+=2;
            space--;
        }
        else if(i> lines){
            asterisk -= 2;
            space++;
        }
    }
 
    return 0;
}