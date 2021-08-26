// A. The Miracle and the Sleeper

#include <iostream>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int a, b;
        cin >> a >> b;

        if (a < b) {
            swap(a, b);
        }

        // (a - b) >= b
        int ans = a % (a / 2 + 1);
        
        if ((a - b) < b) {
            ans = a % b;
        }

        cout << ans << endl;

    }

    return 0;
}
