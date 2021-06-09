// A. Omkar and Bad Story

#include <iostream>
#include <vector>


int main() {

    int t;
    std::cin >> t;

    while (t--) {

        int n;
        std::cin >> n;
        
        std::vector<int> a(n);

        bool ans = true;

        // Editorial - https://codeforces.com/blog/entry/91520
        for (auto &el: a) {
            std::cin >> el;
            if (el < 0) {
                ans = false;
            }
        }

        std::cout << (ans ? "YES" : "NO") << std::endl;

        if (ans) {
            std::cout << 101 << std::endl;
            for (int i = 0; i < 101; ++i) {
                std::cout << i << ' ';
            }
            std::cout << std::endl;
        }
        
    }

    return 0;
}
