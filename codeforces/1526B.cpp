// B. I Hate 1111

#include <iostream>


int main() {

    int t;
    std::cin >> t;

    while (t--) {

        int x;
        std::cin >> x;

        bool ans = false;

        // Idea from - https://codeforces.com/contest/1526/submission/117594170
        for (int i = 0; i < 11; ++i) {
            if (111 * i <= x && (x - 111 * i) % 11 == 0) {
                ans = true;
            }
        }
        
        std::cout << (ans ? "YES" : "NO") << std::endl;
    }

    return 0;
}
