#include<bits/stdc++.h>
using namespace std;
int main(){
        int row, coulmn;
        cin>>row>>coulmn;
        char arr[101][101];
        for(int i =1; i<= row; i++)
        {
            for(int j = 1; j <= coulmn; j++)
            {
                cin>>arr[i][j];
            }
        }
        int Indx1, Indx2;
        cin>>Indx1>>Indx2;
        if(arr[Indx1][Indx2-1] != '.' && 
           arr[Indx1][Indx2+1] != '0' &&
           arr[Indx1-1][Indx2] != '.' &&
           arr[Indx1+1][Indx2] != '.' && 
           arr[Indx1-1][Indx2-1] != '.' &&
           arr[Indx1-1][Indx2+1] != '.' &&
           arr[Indx1+1][Indx2-1] != '.' &&
           arr[Indx1+1][Indx2+1] != '.') 
        {
            cout<<"yes";
        } else
        {
            cout<<"no";
        }
       return 0;
}