#include <bits/stdc++.h>
using namespace std;
int main(){
        int size, num1, num2;
        cin>>size>>num1>>num2;
        int arr[size][size];
        for(int i=0; i< size; i++){
            for(int z=0; z <size; z++){
                cin>>arr[i][z];
            }
        }
        num1--;
        num2--;
        for(int i =0; i <size; i++){
            int temp = arr[num1][i];
            arr[num1][i] = arr[num2][i];
            arr[num2][i] = temp;
        }
        for(int i =0; i< size; i++){
            int temp = arr[i][num2];
            arr[i][num2] = arr[i][num1];
            arr[i][num1] = temp;
        }
        for(int i =0; i< size ; i++){
            for(int z =0 ; z < size; z++){
            cout<<arr[i][z]<<" ";
        }
        cout<<endl;
        }
   	    return 0;
    }