// B. AND Sequences

#include <iostream>
#include <map>

using namespace std;
using ull = unsigned long long;


int main() {

    ull mod = 1e9 + 7;
    
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int tmp;
        map<int, int> a;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            ++a[tmp];
        }

        ull ans;
        
        // Idea - https://www.youtube.com/watch?v=Wqhdmx2ePcI
        // The submission - https://codeforces.com/contest/1513/submission/112669181
        int an = a.begin()->first;
        for (auto &el: a) {
            an &= el.first;
        }

        ans = 1ULL * a[an] * (a[an] - 1) % mod;
        if (ans != 0) {
            for (int i = n-2; i > 0; --i) {
                ans = (ans * i) % mod;
            }
        }

        cout << ans << endl;
        
    }

    return 0;
}
