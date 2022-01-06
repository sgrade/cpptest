// B. Mirror in the String

#include <iostream>
#include <string>
#include <vector>

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
        cin >> s;

        vector<char> ans = {s[0]};
        for (int i = 1; i < n; ++i) {
            if (s[i] > s[i-1]) {
                break;
            }
            else if (s[i] < s[i-1]) {
                ans.push_back(s[i]);
            }
            else {
                if (size(ans) > 1) {
                    ans.push_back(s[i]);
                }
                else {
                    break;
                }
            }
        }

        for (auto &ch: ans) {
            cout << ch;
        }
        for (int i = size(ans) - 1; i > -1; --i) {
            cout << ans[i];
        }
        cout << '\n';
    }

    return 0;
}
