// A. A.M. Deviation

#include <iostream>

int main() {

    int t;
    std::cin >> t;

    while (t--) {

        int a, b, c;
        std::cin >> a >> b >> c;

        // Perfect solution - https://codeforces.com/contest/1605/submission/135103755

        int ans = (a + c - 2 * b) % 3 ? 1 : 0;

        std::cout << ans << std::endl;
    }

    return 0;
}
