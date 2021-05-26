// B. AND 0, Sum Big

#include <iostream>


int main() {

    int t;
    std::cin >> t;

    int mod = 1e9 + 7;
    
    while (t--) {
        int n, k;
        std::cin >> n >> k;

        long long ans = 1;
        
        // Editorial - https://codeforces.com/blog/entry/89810
        for (int i = 0; i < k; ++i) {
            ans = (ans * n) % mod;
        }

        std::cout << ans << std::endl;
    }

    return 0;
}
