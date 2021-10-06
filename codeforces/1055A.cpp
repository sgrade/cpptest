// A. Metro

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int n, s;
    cin >> n >> s;
    --s;

    vector<int> a(n), b(n);
    for (auto &el: a) {
        cin >> el;
    }
    for (auto &el: b) {
        cin >> el;
    }

    bool ans = true;

    if (a[0] == 0) {
        if (s != 0) {
            ans = false;
        }
    }

    else {
        if (a[s] == 0) {
            if (b[s] == 0) {
                ans = false;
            }

            else {
                bool found = false;
                for (int i = s+1; i < n; ++i) {
                    if (a[i] == 1 && b[i] == 1) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    ans = false;
                }
            }
        }
    }

    cout << (ans ? "YES" : "NO") << '\n';

    return 0;
}
