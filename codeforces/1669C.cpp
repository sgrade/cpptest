// C. Odd/Even Increments

#include <iostream>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);
        int tmp;
        bool even = true, odd = true, cur;

        bool ans = true;
        
        cin >> tmp;
        if (tmp % 2 != 0) even = false;
        cin >> tmp;
        if (tmp % 2 != 0) odd = false;

        for (int i = 2; i < n; ++i) {
            cin >> tmp;
            cur = (tmp % 2 == 0 ? true : false);
            if (i % 2 == 0) {
                if (cur != even) ans = false;
            }
            else {
                if (cur != odd) ans = false;
            }
        }

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
