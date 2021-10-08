// A. Consecutive Sum Riddle

#include <iostream>


int main() {

    int t;
    std::cin >> t;

    while (t--) {

        long long n;
        std::cin >> n;

        // Editorial - https://codeforces.com/blog/entry/95525
        std::cout << -n + 1 << ' ' << n << '\n';

    }

    return 0;
}
