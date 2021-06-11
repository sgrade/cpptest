// C. Binary Search
// NOT FINISHED

#include <iostream>
#include <algorithm>

using namespace std;
using ull = unsigned long long;

const int MOD = 1e9 + 7;

unsigned long long fact(ull a, ull b){
    if (a > b) {
        swap(a, b);
    }
    for (ull i = a+1; i<=b; ++i){
        a = (a * i) % MOD;
    }
    return max<ull>(1, a);
}


int main() {

    int n, x, pos;
    cin >> n >> x >> pos;

    ull ans = 1ULL;

    // Editorial - https://codeforces.com/blog/entry/84024
    
    int count_less = 0, count_more = 0;
    int left = 0, right = n, mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (mid <= pos) {
            if (mid != pos) {
                ++count_less;
            }
            left = mid + 1;
        }
        // mid > pos
        else {
            ++count_more;
            right = mid;
        }
    }

    // P(n, r) = n! / (n - r)!
    // 4*3*2*1 / 2*1 = 4*3
    
    int less_than_x = max(0, x - 1);
    int more_than_x = max(0, n - x);

    ull perm_less, perm_more;

    perm_less = fact(less_than_x, count_less);
    perm_more = fact(more_than_x, count_more);

    ull perm_less_more = fact(perm_less, perm_more);

    int count_other = max(0, n - 1 - (count_less + count_more));

    ans = fact(perm_less_more, count_other);

    cout << ans << endl;

    return 0;
}
