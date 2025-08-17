#include <bits/stdc++.h>
using namespace std;
 
int main()
{   
     long long seat;
     cin>>seat;
     long long row = seat /4;
     long long column;
     if(row % 2 == 0){
         column = seat %4;
         
     } else {
         column = 3 -(seat % 4);
     }
     cout<<row<<" "<<column<<endl;
    
    return 0;
}