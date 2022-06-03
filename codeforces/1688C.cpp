// C. Manipulating History

#include <iostream>
#include <string>
#include <map>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        string s;
        map<char, int> cnt;

        for (int i = 0; i < 2 * n + 1; ++i) {
            cin >> s;
            for (char &c: s) {
                ++cnt[c];
            }
        }

        char ans; 
        for (auto &p: cnt) {
            if (p.second % 2 != 0) {
                ans = p.first;
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
