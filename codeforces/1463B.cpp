// B. Find The Array

#include <iostream>
#include <vector>
#include <numeric>

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

        unsigned long long sm = accumulate(begin(a), end(a), 0ULL);

        // Editorial - https://codeforces.com/blog/entry/85707

        unsigned long long sm_odd = 0ULL, sm_even = 0ULL;
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                sm_odd += a[i] - 1;
            }
            else {
                sm_even += a[i] - 1;
            }
        }

        int i = 0;
        if (sm_even > sm_odd) {
            ++i;
        }
        for (; i < n; i += 2) {
            a[i] = 1;
        }

        for (auto &el: a) {
            cout << el << ' ';
        }
        cout << endl;

    }

    return 0;
}
