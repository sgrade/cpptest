// A. Three Doors

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int x;
        cin >> x;

        vector<int> a(4);
        for (int i = 1; i < 4; ++i) cin >> a[i];

        bool ans = true;

        int y;
        for (int i = 0; i < 3; ++i) {
            y = a[x];
            a[x] = -1;
            x = y;
        }

        for (int i = 1; i < 4; ++i) {
            if (a[i] != -1) {
                ans = false;
            }
        }

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
