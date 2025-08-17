using namespace std;
#include <cmath>
#include <iostream>
 
int main()
{
    
    int c;
    cin>>c;
    int mx = -1000000;
    for(int i = 1; i <= c; i++){
        int n;
        cin>>n;
       
        if(n > mx)
            mx = n;
 
    }
                   cout<<mx<<endl;
 
    return 0;
}