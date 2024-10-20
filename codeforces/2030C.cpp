// C. A TRUE Battle

#include <bits/stdc++.h>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        
        string s;
        cin >> s;

        int ans = false;
        if (s[0] == '1')
            ans = true;
        else if (s[n - 1] == '1')
            ans = true;
        else {
            for (int i = 1; i < n; ++i) {
                if (s[i] == '1' && (s[i] == s[i - 1])) {
                    ans = true;
                    break;
                }
            }
        }

        cout << (ans ? "YES" : "NO") << endl;
    }

    return 0;
}
