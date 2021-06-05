// A. Payment Without Change

#include <iostream>


int main() {

    int q;
    std::cin >> q;

    while (q--) {

        unsigned long long a, b, n, S;
        std::cin >> a >> b >> n >> S;

        bool ans = false;

        unsigned long long rem = S % n;
        if (rem <= b && a * n + b >= S) {
            ans = true;
        }

        std::cout << (ans ? "YES" : "NO") << std::endl;

    }

    return 0;
}
