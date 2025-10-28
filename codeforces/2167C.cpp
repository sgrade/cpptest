// C. Isamatdin and His Magic Wand!
// https://codeforces.com/contest/2167/problem/C

#include <bits/stdc++.h>

using namespace std;


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        bool even = false, odd = false;
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 == 0) {
                even = true;
            } else {
                odd = true;
            }
        }

        if (even && odd) {
            sort(a.begin(), a.end());
        }
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
 