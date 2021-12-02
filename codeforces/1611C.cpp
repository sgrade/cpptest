// C. Polycarp Recovers the Permutation

#include <iostream>
#include <vector>


int main() {

    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> p(n);
        for (auto &el: p) {
            std::cin >> el;
        }

        // Editorial - https://codeforces.com/blog/entry/97288
        if (*begin(p) != n && *rbegin(p) != n) {
            std::cout << -1 << std::endl;
        }

        else {
            for (int i = n-1; i > -1; --i) {
                std::cout << p[i] << ' ';
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
