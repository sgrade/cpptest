// A. Forbidden Subsequence

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        string S, T;
        cin >> S >> T;

        sort(begin(S), end(S));

        // Editorial - https://codeforces.com/blog/entry/97920

        map<char, int> cnt;
        for (auto &ch: S) {
            ++cnt[ch];
        }

        bool flag = false;
        vector<char> v = {'a', 'b', 'c'};
        for (auto &el: v) {
            if (cnt.find(el) == end(cnt)) {
                flag = true;
                break;
            }
        }

        if (flag || T != "abc") {
            for (auto &ch: S) {
                cout << ch;
            }
            cout << endl;
        }
        
        else {
            vector<char> acb = {'a', 'c', 'b'};
            for (auto &ch: acb) {
                while (cnt[ch] > 0) {
                    cout << ch;
                    --cnt[ch];
                }
            }
            for (auto &p: cnt) {
                    while (p.second > 0) {
                        cout << p.first;
                        --p.second;
                    }
            }
            cout << endl;
        }

    }

    return 0;
}
