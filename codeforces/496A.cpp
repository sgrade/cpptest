// A. Minimum Difficulty

#include <iostream>
#include <vector>
#include <limits>


int main() {

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (auto &el: a) {
        std::cin >> el;
    }

    int ans = std::numeric_limits<int>::max();
    for (int i = 1; i < n-1; ++i) {
        int cur_ans = 0;
        for (int j = 1; j < n; ++j) {
            if (i == j) {
                cur_ans = std::max(cur_ans, a[j+1] - a[j-1]);
                ++j;
            }
            else {
                cur_ans = std::max(cur_ans, a[j] - a[j-1]);
            }
        }
        ans = std::min(ans, cur_ans);
    }

    std::cout << ans << std::endl;

    return 0;
}
