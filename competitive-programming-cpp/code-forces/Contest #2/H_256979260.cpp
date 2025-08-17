#include <iostream>
 
using namespace std;
 
int main() {
    long long N;
    cin >> N;
 
    // Try all possible values of X and Y within the given constraints
    for (long long X = 0; X <= 1000000000; ++X) {
        for (long long Y = 0; Y <= 1000000000; ++Y) {
            if ((X*X + Y*Y) % N == 0) {
                cout << X << " " << Y << endl;
                return 0;
            }
        }
    }
 
    // If no solutions found, print "No solutions"
    cout << "No solutions" << endl;
 
    return 0;
}