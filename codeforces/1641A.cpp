// A. Great Sequence

#include <iostream>
#include <set>
#include <algorithm>
#include <limits.h>

using namespace std;
using ll = long long;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, x;
        cin >> n >> x;

        int tmp;
        multiset<int> a;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            a.insert(tmp);
        }

        int mx = *rbegin(a);
        int cnt = 0;

        multiset<int>::iterator it1 = begin(a), it2;

        int iii = INT_MAX;

        while (true) {
            
            if (it1 == end(a) || size (a) < 2) {
                break;
            }

            // (*it2 > INT_MAX / x) if integer overflow
            // https://stackoverflow.com/questions/199333/how-do-i-detect-unsigned-integer-multiply-overflow
            if (*it1 > INT_MAX / x) {
                break;
            }

            tmp = *it1 * x;
            if (tmp > mx) {
                break;
            }

            it2 = a.find(tmp);

            if (it2 != end(a)) {
                a.erase(it2);
                ++cnt;
            }

            ++it1;
        }

        cout << n - cnt * 2 << '\n';
    }

    return 0;
}
