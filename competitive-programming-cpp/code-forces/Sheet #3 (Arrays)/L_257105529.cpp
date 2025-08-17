using namespace std;
#include <iostream>
int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int size;
        cin >> size;
        int *arr = new int[size];
        for (int i = 0; i < size; i++)
            cin >> arr[i];
 
        for (int i = 0; i < size; i++)
        {
            int maxRes;
            for (int x = i; x < size; x++)
            {
                if (i == x)
                {
                    maxRes = arr[x];
                    cout << maxRes << " ";
                    continue;
                }
 
                maxRes = max(maxRes, arr[x]);
                cout << maxRes << " ";
            }
        }
 
        cout << endl;
    }
}