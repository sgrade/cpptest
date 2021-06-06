// C. Sum of Cubes

#include <iostream>
#include <unordered_set>

using ull = unsigned long long;


int main() {

    // Editorial = https://codeforces.com/blog/entry/87874
    std::unordered_set<ull> dp;
    for (ull i = 1; i < 10001; ++i) {
        dp.insert(i * i * i);
    }

    int t;
    std::cin >> t;

    while (t--) {
        ull x;
        std::cin >> x;

        bool ans = false;

        for (ull i = 1; i < 10001; ++i) {
            if (dp.count(x - i * i * i)) {
                ans = true;
                break;
            }
        }

        std::cout << (ans ? "YES" : "NO") << std::endl;
    }

    return 0;
}
