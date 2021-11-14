// B. Coloring Rectangles

#include <iostream>


int main() {

    int t;
    std::cin >> t;

    while (t--) {

        int n, m;
        std::cin >> n >> m;

        int ans;

        // Idea is from - https://codeforces.com/contest/1589/submission/135346164
        ans = (n * m + 2) / 3;
        
        std::cout << ans << std::endl;
    }

    return 0;
}
