#include<bits/stdc++.h>
using namespace std;
int main(){
    int r, c;
    cin>>r>>c;
    int arr[r][c];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin>>arr[i][j];
        }
     } int search, flag = 0;
     cin>>search; 
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(arr[i][j] == search){
                flag = 1;
                break;
            }
        }
    }
    if(flag == 1){
        cout<<"will not take number"<<endl;
    } else {
        cout<<"will take number"<<endl;
    }
    return 0;
}