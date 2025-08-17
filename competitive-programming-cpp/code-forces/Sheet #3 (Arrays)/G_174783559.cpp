#include <bits/stdc++.h>
using namespace std;
 
int main()
{   
    int size, flag = 0;
    cin>>size;
    int nums[size];
    for(int i=0 ; i < size ; i++){
        cin>>nums[i];
        
    }
    for(int i = 0; i <= size/2 ; i++){
        if(nums[i] != nums[size - 1 - i]){
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
    return 0;
}