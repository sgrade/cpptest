// C. String Equality

#include <iostream>
#include <string>
#include <map>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        string a, b;
        getline(cin >> ws, a);
        getline(cin >> ws, b);

        // Editorial - https://codeforces.com/blog/entry/84885
        map<int, int> cnt_a, cnt_b;
        for (int i = 0; i < 26; ++i) {
            cnt_a[i];
            cnt_b[i];
        }

        for (auto &ch: a) {
            ++cnt_a[ch - 'a'];
        }
        for (auto &ch: b) {
            ++cnt_b[ch - 'a'];
        }

        bool ans = true;
        map<int, int>::iterator it = begin(cnt_a);
        int tmp = 0;
        for (int i = 0; i < 26; ++i) {
            it->second += tmp;

            if (cnt_a[i] < cnt_b[i]) {
                ans = false;
                break;
            }

            cnt_a[i] -= cnt_b[i];
            if (cnt_a[i] % k != 0) {
                ans = false;
                break;
            }

            tmp = cnt_a[i];
            ++it;
        }

        cout << (ans ? "YES" : "NO") << endl;

    }

    return 0;
}
