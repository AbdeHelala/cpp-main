#include <bits/stdc++.h>
using namespace std;
 
int main()
{   
    int size, seq;
    cin>>size>>seq;
    int min, flag = 1;
    int counter = 0;
    for(int i = 1; i <= size; i++){
        int val;
        cin>>val;
        if(flag){
            min = val;
            flag = 0;
        } else {
            if(val < min){
                min = val;
                
            }
        }
        counter++;
        if(counter == seq || i == size ){
            cout<<min<<" ";
            counter = 0;
            flag = 1;
        }
    }
    return 0;
}