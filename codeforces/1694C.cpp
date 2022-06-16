// C. Directional Increase
// NOT FINISHED

#include <iostream>
#include <algorithm>
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
        int zeroes = 0;
        for (int &el: a) {
            cin >> el;
        }

        for (int i = n - 1; i > -1; ++i) {
            if (a[i] == 0) ++zeroes;
            else break;
        }

        long long sum = accumulate(a.begin(), a.end(), 0LL);
        
        bool ans = false;

        if (sum == 0 && (n - zeroes) % 2 == 0) ans = true;

        cout << (ans ? "Yes\n": "No\n");
    }

    return 0;
}
