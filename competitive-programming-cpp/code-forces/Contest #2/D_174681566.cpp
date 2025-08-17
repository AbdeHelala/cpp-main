#include <bits/stdc++.h>
using namespace std;
 
int main()
{   
    long long size;
    cin>>size;
    for(int i = 1; i <= size; i++){
        long long start, end;
        long long mini, maxi;
        cin>>start>>end;
        maxi = max(start, end);
        mini = min(start, end);
        mini--;
        long long res1 = mini * (mini+1) / 2;
        long long res2 = maxi * (maxi + 1) / 2;
        cout<<res2-res1<<endl;
         
        }
    
    return 0;
}