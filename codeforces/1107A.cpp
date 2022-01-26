// A. Digits Sequence Dividing

#include <iostream>
#include <string>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    while (q--) {
        
        int n;
        cin >> n;

        string s;
        cin >> s;

        bool ans = true;
        
        if (n == 2 && s[0] >= s[1]) {
            ans = false;
        }

        cout << (ans ? "YES" : "NO") << '\n';

        if (ans) {
            cout << 2 << '\n';
            cout << s[0] << ' ';
            for (int i = 1; i < n; ++i) {
                cout << s[i];
            }
            cout << '\n';
        }
    }

    return 0;
}
