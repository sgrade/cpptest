// A. Digits Sum

#include <iostream>


int main() {

    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        // Editorial - https://codeforces.com/blog/entry/93105
        int ans = (n + 1) / 10;
        std::cout << ans << std::endl;
    }

    return 0;
}
