#include<bits/stdc++.h>
using namespace std;
int countDivis(int num){
    int counter =0;
    for(int i = 1; i <= sqrt(num); i++){
        if(num % i == 0){
            counter++;
        }
    }
    return counter;
}
bool palindrome(int num){
    int tmp = num;
    int sum = 0;
    int d;
    while(num){
        d = num%10;
        sum=(sum*10) + d;
        num /= 10;
    }
    if(tmp == sum){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i =0; i< size; i++){
        cin>>arr[i];
    }
    sort(arr, arr+size);
    cout<<"The maximum number : "<<arr[size-1]<<endl;
    cout<<"The minimum number : "<<arr[0]<<endl;
    int countPrime = 0, countPalin = 0;
    for(int i = 0; i< size; i++){
        if(palindrome(arr[i])){
            countPalin++;
        }
        int m = arr[i]/2;
        int flag = 0;
        for(int z =2; z <= m; z++){
        if(arr[i]%z == 0){
            flag = 1;
            break;
        }
    }
    if(flag == 0 && arr[i] != 1) countPrime++;
 }
 cout<<"The number of prime numbers : "<<countPrime<<endl;
 cout<<"The number of palindrome numbers : "<<countPalin<<endl;
 int c, max, index;
 for(int i = 0; i < size; i++){
     c = countDivis(arr[i]);
     if(i == 0){
         max = c;
         index = i;
     } else{
         if(c >= max){
             max = c;
             index = i;
         }
     }
 }
 cout<<"The number that has the maximum number of divisors : "<<arr[index]<<endl;
}