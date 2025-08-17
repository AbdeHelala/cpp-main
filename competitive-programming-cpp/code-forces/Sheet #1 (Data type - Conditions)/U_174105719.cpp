#include <iostream>
using namespace std;
 
int main()
{
    double num;
    cin>> num;
    int INTnum = num;
    double result = num - INTnum;
    if(result != 0){
        cout<<"float " << INTnum<<" "<<result<<endl;
    } else{
        cout<<"int "<<INTnum<<endl;
    }
    
    return 0;
}