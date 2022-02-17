// B. Captain Flint and a Long Voyage

#include <iostream>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        // Editorial - https://codeforces.com/blog/entry/80828
        // Some ideas - https://codeforces.com/contest/1388/submission/131706626

        int eights = (n + 4 - 1) / 4;
        for (int i = 0; i < n - eights; ++i) {
            cout << 9;
        }
        for (int i = 0; i < eights; ++i) {
            cout << 8;
        }
        cout << '\n';
    }

    return 0;
}
