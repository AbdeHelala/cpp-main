#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Read number of cities and range limits for beamers (k) and catapults (l)
    int n, k, l;
    cin >> n >> k >> l;

    // Read the layout of the cities (0 = nothing, 1 = beamer, 2 = catapult)
    vector<int> cities(n);
    for (int i = 0; i < n; ++i) {
        cin >> cities[i];
    }

    // Track coverage from beamers and which beamers were actually used
    vector<bool> covered(n, false);
    vector<bool> usedBeamer(n, false);
    int beamerCount = 0;

    // First, mark coverage from existing beamers — only if they cover new cities
    for (int i = 0; i < n; ++i) {
        if (cities[i] == 1) {
            int left = max(0, i - (k - 1));
            int right = min(n - 1, i + (k - 1));
            bool didCover = false;
            for (int j = left; j <= right; ++j) {
                if (!covered[j]) {
                    covered[j] = true;
                    didCover = true;
                }
            }
            if (didCover) {
                usedBeamer[i] = true;
            }
        }
    }

    // If any city is still not covered, try to enable a nearby beamer
    for (int i = 0; i < n; ++i) {
        if (!covered[i]) {
            bool found = false;
            for (int j = min(n - 1, i + (k - 1)); j >= max(0, i - (k - 1)); --j) {
                if (cities[j] == 1) {
                    int left = max(0, j - (k - 1));
                    int right = min(n - 1, j + (k - 1));
                    bool didCover = false;
                    for (int m = left; m <= right; ++m) {
                        if (!covered[m]) {
                            covered[m] = true;
                            didCover = true;
                        }
                    }
                    if (didCover) {
                        usedBeamer[j] = true;
                    }
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "beamer:-1" << endl;
                cout << "cata:-1" << endl;
                return 0;
            }
        }
    }

    // Count how many beamers were actually used to provide coverage
    for (int i = 0; i < n; ++i) {
        if (usedBeamer[i]) ++beamerCount;
    }
    cout << "beamer:" << beamerCount << endl;

    // Now do the same for catapults
    vector<bool> catapultCovered(n, false);
    int catapultCount = 0;
    bool catapultFailed = false;

    for (int i = 0; i < n; ++i) {
        if (!catapultCovered[i]) {
            bool found = false;
            for (int j = min(n - 1, i + (l - 1)); j >= max(0, i - (l - 1)); --j) {
                if (cities[j] == 2) {
                    int left = max(0, j - (l - 1));
                    int right = min(n - 1, j + (l - 1));
                    for (int m = left; m <= right; ++m) {
                        catapultCovered[m] = true;
                    }
                    ++catapultCount;
                    found = true;
                    break;
                }
            }
            if (!found) {
                catapultFailed = true;
                break;
            }
        }
    }

    if (catapultFailed) {
        cout << "cata:-1" << endl;
    } else {
        cout << "cata:" << catapultCount << endl;
    }

    return 0;
}
