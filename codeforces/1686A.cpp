// A. Everything Everywhere All But One

#include <iostream>
#include <vector>
#include <numeric>

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
        for (int &el: a) cin >> el;

        int sum = accumulate(a.begin(), a.end(), 0);

        bool ans = false;
        
        int x;
        for (int i = 0; i < n; ++i) {
            x = sum - a[i];
            if (x % (n - 1) == 0 && x / (n - 1) == a[i]) {
                ans = true;
                break;
            }
        }

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
