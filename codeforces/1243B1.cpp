// B1. Character Swap (Easy Version)

#include <iostream>
#include <string>

using namespace std;


int main() {

    int k;
    cin >> k;

    while (k--) {
        int n;
        cin >> n;

        string s, t;
        cin >> s >> t;

        bool ans = true;

        int i = -1;
        for (; i < n; ++i) {
            if (s[i] != t[i]) {
                break;
            }
        }

        if (i != -1) {
            bool another_diff = false;
            int j = i + 1;
            for (; j < n; ++j) {
                if (s[j] != t[j]) {
                    another_diff = true;
                    break;
                }
            }
            if (another_diff) {
                swap(s[i], t[j]);
            }
            else {
                swap(s[i], t[i]);
            }

            if (s != t) {
                ans = false;
            }
        }

        cout << (ans ? "Yes\n" : "No\n");
    }

    return 0;
}
