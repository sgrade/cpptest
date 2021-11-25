// A. Anti Light's Cell Guessing

#include <iostream>


int main() {

    int t;
    std::cin >> t;

    while (t--) {
        int n, m;
        std::cin >> n >> m;

        int ans;

        // Editorial - https://codeforces.com/blog/entry/97179
        
        int mn = std::min(n, m);
        int mx = std::max(n, m);

        if (mn == 1) {
            if (mx == 1) {
                ans = 0;
            }
            else {
                ans = 1;
            }
        }

        else {
            ans = 2;
        }

        std::cout << ans << std::endl;
    }

    return 0;
}
