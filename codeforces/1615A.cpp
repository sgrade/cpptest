// A. Closing The Gap

#include <iostream>

int main() {

    int t;
    std::cin >> t;

    while (t--) {

        int n;
        std::cin >> n;

        unsigned long long sm = 0ULL;
        unsigned long long tmp;

        for (int i = 0; i < n; ++i) {
            std::cin >> tmp;
            sm += tmp;
        }

        int rem = sm % n;

        std::cout << (rem == 0 ? 0 : 1) << std::endl;
    }

    return 0;
}
