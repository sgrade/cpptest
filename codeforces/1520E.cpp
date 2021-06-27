// E. Arranging The Sheep

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;
    
    while (t--) {

        int n;
        cin >> n;

        string s;
        getline(cin >> ws, s);

        long long ans = 0;

        // Key ideas from https://codeforces.com/contest/1520/submission/118467369
        int cnt = count(begin(s), end(s), '*');
        if (0 < cnt && cnt < n) {
            int stars_passed = 0;
            for (auto &ch: s) {
                if (ch == '*') {
                    ++stars_passed;
                }
                else {
                    // Editorial - https://codeforces.com/blog/entry/90342
                    // min shows if we passed mid star or not
                    ans += min(stars_passed, cnt - stars_passed);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
