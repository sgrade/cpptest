//  A. Sequence with Digits

#include <iostream>
#include <limits>

using ull = unsigned long long;


int main() {

    int t;
    std::cin >> t;

    while (t--) {

        ull a, k;
        std::cin >> a >> k;

        // Editorial - https://codeforces.com/blog/entry/77491

        for (ull i = 0; i < k-1; ++i) {
            ull mn = std::numeric_limits<ull>::max();
            ull mx = 0;

            ull tmp = a;
            while (tmp > 0) {
                ull rem = tmp % 10;
                mn = std::min(mn, rem);
                mx = std::max(mx, rem);
                tmp /= 10;
            }
            tmp = mn * mx;
            if (tmp == 0) {
                break;
            }
            a += tmp;
        }

        std::cout << a << std::endl;

    }

    return 0;
}
