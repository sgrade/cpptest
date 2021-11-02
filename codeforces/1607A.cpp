// A. Linear Keyboard

#include <iostream>
#include <string>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        string k, s;
        cin >> k >> s;

        int ans = 0;

        int prev = k.find(s[0]), cur;
        for (int i = 1; i < size(s); ++i) {
            cur = k.find(s[i]);
            ans += abs(prev - cur);
            prev = cur;
        }

        cout << ans << endl;

    }

    return 0;
}
