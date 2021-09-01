// A. Stickers and Toys

#include <iostream>


int main() {

    int T;
    std::cin >> T;

    while (T--) {
        int n, s, t;
        std::cin >> n >> s >> t;

        int ans = std::max(n - s, n - t) + 1;
        std::cout << ans << std::endl;
    }

    return 0;
}
