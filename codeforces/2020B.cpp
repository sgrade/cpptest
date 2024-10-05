// B. Brightness Begins

#include <iostream>
#include <cmath>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        long long k;
        cin >> k;

        // Editorial - https://codeforces.com/blog/entry/134516
        long long n = k + sqrt(k) + 0.5;
        cout << n << endl;
    }

    return 0;
}
