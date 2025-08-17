#include<bits/stdc++.h>
using namespace std;
int main() {
    long long x[1000];
    long long y[1000];
    long long n1 , n2, diameter, points;
    cin>>n1>>n2>>diameter>>points;
    for(int i = 0; i< points; i++){
        cin>>x[i]>>y[i];
    }
    for(int i = 0; i < points ; i++){
         long long x1 = n1 - x[i];
        long long y1 = n2 - y[i];
        double r = sqrt((x1 * x1) + (y1 *y1));
        if(r > diameter){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
  
  
  
  
    return 0;
}