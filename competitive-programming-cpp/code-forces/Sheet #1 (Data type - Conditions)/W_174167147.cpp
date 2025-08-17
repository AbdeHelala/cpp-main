#include<bits/stdc++.h>
using namespace std;
void validate(int result, int myResult){
    if(myResult == result){
        cout<<"Yes"<<endl;
    } else{
        cout<<myResult<<endl;
    }
    return;
}
int main()
{
    int num1,  num2, Res;
    char opr, oprRes;
    int myResult = 0;
    cin>>num1>>opr>>num2>>oprRes>>Res;
    switch(opr){
        case '+':
        myResult = num1 + num2;
        validate(Res, myResult);
        break;
        case '-':
        myResult = num1 - num2;
        validate(Res, myResult);
        break;
        case '*':
        myResult = num1 * num2;
        validate(Res, myResult);
        break;
    return 0;
}
}