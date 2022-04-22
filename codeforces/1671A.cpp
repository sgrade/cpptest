// A. String Building

#include <iostream>
#include <string>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        string s;
        cin >> s;

        bool ans = true;

        int n = s.size();
        
        int cnt = 1;
        char prev = s[0];
        for (int i = 1; i < n; ++i) {
            if (s[i] == prev) ++cnt;
            else {
                if (cnt < 2) {
                    ans = false;
                    break;
                }
                cnt = 1;
                prev = s[i];
            }
        }

        if (cnt < 2) ans = false;

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
