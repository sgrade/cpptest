// B. Luntik and Subsequences

#include <iostream>


int main() {

    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        long long ans = 0, tmp, zeroes = 0, ones = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> tmp;
            if (tmp == 0) {
                ++zeroes;
            }
            else if (tmp == 1) {
                ++ones;
            }
        }

        // Editorial - https://codeforces.com/blog/entry/96267

        long long num_of_ways_to_chooose_zero;
        // https://math.stackexchange.com/questions/1193947/number-of-ways-to-pick-one-or-more-elements-from-a-set-of-n-elements
        // Note: empty subsequence is included, so no "-1" in the formula
        num_of_ways_to_chooose_zero = 1LL << zeroes;

        ans = 1LL * num_of_ways_to_chooose_zero * ones;


        std::cout << ans << std::endl;
    }

    return 0;
}
