using namespace std;
#include <iostream>
int main()
{
    int n;
    cin>>n;
    int first_digit = n % 10;
    int second_digit = n / 10;
    if(first_digit % second_digit == 0 || second_digit % first_digit == 0)
            cout<<"YES"<<endl;
    else
            cout<<"NO"<<endl;
 
    return 0;
}