#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int num, times;
    cin >> times;
 
    for (int i = 1; i <= times; i++)
    {
        cin >> num;
        int p = 0;
        int dec_sum = 0;
 
        while (num != 0)
        {
 
            if (num % 2 == 1)
            {
                dec_sum += 1 * pow(2, p);
                p++;
            }
            num /= 2;
        }
 
        cout << dec_sum << endl;
    }
}