// A. Polycarp and Coins

#include <iostream>

int main() {

    int t;
    std::cin >> t;

    while (t--) {

        int n;
        std::cin >> n;

        int c1, c2;

        c1 = n / 3;
        c2 = c1;

        int rem = n % 3;
        if (rem == 1) {
            ++c1;
        }
        else if (rem == 2) {
            ++c2;
        }

        std::cout << c1 << ' ' << c2 << std::endl;
    }

    return 0;
}
