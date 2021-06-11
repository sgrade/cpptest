// A. Stone Game

#include <iostream>
#include <vector>
#include <algorithm>


int main() {

    int t;
    std::cin >> t;

    while (t--) {

        int n;
        std::cin >> n;

        std::vector<int> a(n);
        int mn = 101, mx = 0, tmp, mn_idx, mx_idx;
        for (int i = 0; i < n; ++i) {
            std::cin >> tmp;
            if (tmp < mn) {
                mn = tmp;
                mn_idx = i;
            }
            if (tmp > mx) {
                mx = tmp;
                mx_idx = i;
            }
        }

        std::vector<int> distances = {mn_idx + 1, mx_idx + 1, n - mn_idx, n - mx_idx};
        std::sort(begin(distances), end(distances));

        int ans = distances[0];
        ans += std::min(distances[1], abs(mn_idx - mx_idx));

        std::cout << ans << std::endl;

    }

    return 0;
}