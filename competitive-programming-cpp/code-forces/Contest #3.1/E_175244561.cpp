#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
    int size;
    cin>>size;
    int arr1[size], arr2[size];
    for(int i =0; i < size ;i++){
        int value;
        cin>>value;
        arr1[i] = value;
        arr2[i] = value;
    }
    int tmp1= 0, cntr1= 0, tmp2=0, cntr2=1;
    arr2[0] *= -1;
    for(int i =0; i< size; i++){
        if(i == 0){
            tmp1=arr1[i];
            tmp2 =arr2[i];
        } else{
            if((tmp1 > 0 && arr1[i] > 0) || (tmp1 < 0 && arr1[i] <0)){
                arr1[i] *= -1;
                cntr1++;
            }
            if((tmp2 > 0 && arr2[i] > 0) || (tmp2 < 0 && arr2[i]<0)){
                arr2[i] *= -1;
                cntr2++;
            }
            tmp1 = arr1[i];
            tmp2 =arr2[i];
        } 
    }
    if(cntr1 < cntr2){
        cout<<cntr1<<endl;
    } else{
        cout<<cntr2<<endl;
    }
    
  return 0;
}