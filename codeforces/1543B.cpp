// B. Customising the Track

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;
using ull = unsigned long long;


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

        ull sm = accumulate(begin(a), end(a), 0ULL);
        ull reminder = sm % n;

        ull ans = (n - reminder) * reminder;

        cout << ans << endl;
    }

    return 0;
}
