// A. Dislike of Threes

#include <iostream>
#include <vector>


std::vector<int> dp = {1, 2, 4, 5, 7, 8, 10, 11, 14, 16};


int main() {

    int t;
    std::cin >> t;

    while (t--) {

        int k;
        std::cin >> k;

        int ans;

        if (k <= dp.size()) {
            ans = dp[k-1];
        }

        // k > dp.size()
        else {
            k -= dp.size();
            int x = dp[dp.size()-1];
            while (k--) {
                ++x;
                if (x % 3 == 0 || x % 10 == 3) {
                    ++k;
                    continue;
                }
                dp.push_back(x);
            }
            ans = dp[dp.size()-1];
        }

        std::cout << ans << std::endl;

    }

    return 0;
}
