// A. Square?
// https://codeforces.com/contest/2167/problem/A


#include <bits/stdc++.h>

using namespace std;


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {

        vector<int> sides(4);
        for (int i = 0; i < 4; ++i) {
            cin >> sides[i];
        }

        if (sides[0] == sides[1] && sides[0] == sides[2] && sides[1] == sides[3]) {
            cout << "YES" << endl;
            continue;
        }

        cout << "NO" << endl;
    }

    return 0;
}
