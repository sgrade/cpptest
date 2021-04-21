// B. Candies Division

#include <iostream>


int main() {

    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::cin >> n >> k;

        int ans = n;
        
        if (n % k != 0) {
            if (n < k) {
                ans = std::min(n, k / 2);
            }
            else if (n > k) {
                ans = n / k * k + std::min(n % k, k / 2);
            }
        }
        
        std::cout << ans << std::endl;
    }

    return 0;
}
