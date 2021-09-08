// A. Balanced Substring

#include <iostream>
#include <string>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        string s;
        getline(cin >> ws, s);

        pair<int, int> ans(-1, -1);

        for (int i = 1; i < n; ++i) {
            if (s[i] != s[i-1]) {
                ans.first = i;
                ans.second = i + 1;
                break;
            }
        }

        cout << ans.first << ' ' << ans.second << endl;

    }

    return 0;
}
