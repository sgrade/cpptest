// A. Parity

#include <iostream>


int main() {

    int b, k;
    std::cin >> b >> k;

    bool odd = false;

    int tmp;
    bool b_is_even = !(b % 2);
    for (int i = 0; i < k; ++i) {
        std::cin >> tmp;

        if (b_is_even && i != k - 1) {
            continue;
        }

        if (tmp % 2 != 0) {
            odd = !odd;
        }
    }

    std::cout << (odd ? "odd" : "even") << std::endl;

    return 0;
}
