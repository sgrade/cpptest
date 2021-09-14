// A. Median Maximization

#include <iostream>


int main() {

    int t;
    std::cin >> t;

    while (t--) {
        
        int n, s;
        std::cin >> n >> s;

        int m = n / 2 + 1;
        
        int ans = s / m;

        std::cout << ans << std::endl;
    }

    return 0;
}
