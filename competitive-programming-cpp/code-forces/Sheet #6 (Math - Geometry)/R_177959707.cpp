#include<bits/stdc++.h>
using namespace std;
int main() {
   
   double x1, x2, y1, y2;
   cin>>x1>>y1>>x2>>y2;
   double x = x1 - x2;
   double y = y1 - y2;
   double r = sqrt((x*x) + (y*y));
   cout<<fixed<<setprecision(9)<<r<<endl;
    return 0;
}