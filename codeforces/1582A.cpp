// A. Luntik and Concerts

#include <iostream>


int main() {

    int t;
    std::cin >> t;

    while (t--) {

        int a, b, c;
        std::cin >> a >> b >> c;

        // Editorial - https://codeforces.com/blog/entry/96267
        int ans = (a + c) % 2;

        std::cout << ans << std::endl;
    }

    return 0;
}
