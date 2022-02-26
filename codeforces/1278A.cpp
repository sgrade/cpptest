// A. Shuffle Hashing

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        string p, h;
        cin >> p >> h;

        bool ans = false;

        int n = size(p);

        map<char, int> cnt_p;
        for (char &ch: p) {
            ++cnt_p[ch];
        }

        int left = 0, right = n;
        while (right <= size(h)) {
            map<char, int> cnt;
            for (int i = left; i < right; ++i) {
                ++cnt[h[i]];
            }

            if (size(cnt) == size(cnt_p)) {
                if (equal(begin(cnt), end(cnt), begin(cnt_p), end(cnt_p))) {
                    ans = true;
                    break;
                }
            }

            ++left;
            ++right;
        }

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
