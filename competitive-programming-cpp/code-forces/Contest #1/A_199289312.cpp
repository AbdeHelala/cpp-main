#include <iostream>
 
using namespace std;
 
int main() {
    double discount, price_after_discount;
    cin >> discount;
    cin >> price_after_discount;
    double price_before_discount = price_after_discount / (1 - discount/100);
    cout<< price_before_discount << endl;
    return 0;
}