// A. Shifting Stacks

#include <iostream>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        long long h[n];
        for (auto &el: h) {
            cin >> el;
        }

        bool ans = true;

        if (n > 1) {

            long long tmp = h[0];
            long long mn = 0;
            h[0] = 0;
            for (int i = 1; i < n; ++i) {
                if (h[i] > h[i-1]) {
                    tmp += h[i] - (h[i-1] + 1);
                }
                else {
                    tmp -= h[i-1] + 1 - h[i];
                }
                h[i] = h[i-1] + 1;

                if (tmp < 0) {
                    ans = false;
                    break;
                }
            }
        }
        
        cout << (ans ? "YES" : "NO") << endl;

    }

    return 0;
}
