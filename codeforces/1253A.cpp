// A. Single Push

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

        vector<int> a(n), b(n);
        for (int &el: a) {
            cin >> el;
        }
        for (int &el: b) {
            cin >> el;
        }

        int l = 0, r = n-1;
        for (; l < n; ++l) {
            if (a[l] != b[l]) {
                break;
            }
        }
        for (; r >= l; --r) {
            if (a[r] != b[r]) {
                break;
            }
        }

        bool ans = true;

        if (l < n) {
            int d = b[l] - a[l];
            if (d <= 0) {
                ans = false;    
            }
            else {    
                ++l;
                while (l <= r) {
                    if (b[l] - a[l] != d) {
                        ans = false;
                        break;
                    }
                    ++l;
                }
            }
        }
        
        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
