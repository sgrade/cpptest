// A. Find The Array

#include <iostream>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int s;
        cin >> s;

        int ans = 1;

        int sm, i, cur;
        if (s > 1) {
            sm = 1;
            cur = 3;
            while (sm < s) {
                ++ans;
                sm += cur;
                cur += 2;
            }
        }

        cout << ans << endl;

    }

    return 0;
}
