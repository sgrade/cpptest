// A. Mean Inequality

#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    int t;
    std::cin >> t;

    while (t--) {

        int n;
        std::cin >> n;

        std::vector<int> a(2*n);
        for (auto &el: a) {
            std::cin >> el;
        }

        std::sort(begin(a), end(a));

        std::vector<int> b(2*n);
        int j = 0;
        for (int i = 0; i < 2 * n - 1; i += 2, ++j) {
            b[i] = a[j];
        }
        for (int i = 1; i < 2 * n; i += 2, ++j) {
            b[i] = a[j];
        }

        for (auto &el: b) {
            std::cout << el << ' ';
        }
        std::cout << std::endl;

    }

    return 0;
}
