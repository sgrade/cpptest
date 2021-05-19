// B. AGAGA XOOORRR

#include <iostream>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &el: a) {
            cin >> el;
        }

        bool ans = false;
        
        // Idea - https://codeforces.com/contest/1516/submission/113737261
        
        int x = 0; 
        for (auto &el: a) {
            x ^= el;
        }
        
        if (x == 0) {
            ans = true;
        }

        else {
            int preXor = a[0];
            for (int i = 1; i < n; ++i) {
                int midXor = a[i];
                for (int j = i+1; j < n; ++j) {
                    if (preXor == midXor && midXor == x) {
                        ans = true;
                        goto OUTER;
                    }
                    midXor ^= a[j];
                }
                preXor ^= a[i];
            }
        }

        OUTER: cout << (ans ? "YES" : "NO") << endl;

    }

    return 0;
}
