// A. Countdown

#include <iostream>
#include <string>

int main() {

    int t;
    std::cin >> t;

    while (t--) {

        int n;
        std::cin >> n;
        
        std::string s;
        std::cin >> s;

        int ans = 0;

        int tmp;
        for (int i = n-1; i > -1; --i) {
            
            tmp = s[i] - 48;
            ans += tmp;
            
            // Swaps
            if (tmp > 0) {
                // last swap should be zero (no swap required), rest should be one (swap required)
                ans += std::min(1, n-1 - i);
            }
        }
        
        std::cout << ans << std::endl;
    }

    return 0;
}
