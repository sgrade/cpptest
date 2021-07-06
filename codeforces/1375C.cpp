// C. Element Extermination

#include <iostream>
#include <vector>

int main() {

    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for (auto &el: a) {
            std::cin >> el;
        }

        bool ans = false;

        // Editorial - https://codeforces.com/blog/entry/79731
        if (a[0] < a[n-1]) {
            ans = true;
        }

        std::cout << (ans ? "YES" : "NO") << std::endl;
    }

    return 0;
}
