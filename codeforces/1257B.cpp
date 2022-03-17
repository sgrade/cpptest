// B. Magic Stick

#include <iostream>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int x, y;
        cin >> x >> y;

        bool ans = false;

        // Editorial - https://codeforces.com/blog/entry/71434

        if (x == 1 && y == 1) {
            ans = true;
        }
        
        if ((x == 2 || x == 3) && y < 4) {
            ans = true;
        }

        if (x > 3) {
            ans = true;
        }

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
