// A. Era

#include <iostream>


int main() {

    int t;
    std::cin >> t;

    while (t--) {

        int n;
        std::cin >> n;

        int ans = 0;
        int tmp;

        for (int i = 1; i < n+1; ++i) {
            std::cin >> tmp;
            ans = std::max(ans, tmp - i);
        }

        std::cout << ans << std::endl;

    }

    return 0;
}
