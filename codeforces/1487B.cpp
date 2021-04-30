// B. Cat Cycle

#include <iostream>

int main() {

    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::cin >> n >> k;

        int ans = 0;

        // Editorial - https://codeforces.com/blog/entry/87873
        --k;

        // std::cout << "Jury: " << (k+n%2*k/(n/2))%n+1 << std::endl;
        if (n % 2 == 0) {
            ans = k % n + 1;
        }
        
        else {
            int b_extra_steps = k / (n / 2);
            ans = (k + b_extra_steps) % n + 1;
        }

        std::cout << ans << std::endl;
    }

    return 0;
}
