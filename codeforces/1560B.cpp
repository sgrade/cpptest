// B. Who's Opposite?

#include <iostream>
#include <algorithm>


int main() {

    int t;
    std::cin >> t;

    while (t--) {

        int a, b, c;
        std::cin >> a >> b >> c;

        int n = abs(a - b) * 2;

        int ans;

        if (std::max({a, b, c}) > n) {
            ans = -1;
        }
        
        else {
            ans = c + abs(a - b);
            if (ans > n) {
                ans %= n;
            }
        }

        std::cout << ans << std::endl;
    }

    return 0;
}
