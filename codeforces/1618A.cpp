// A. Polycarp and Sums of Subsequences

#include <iostream>
#include <vector>


int main() {

    int t;
    std::cin >> t;

    while (t--) {
        std::vector<int> b(7);
        for (auto &el: b) {
            std::cin >> el;
        }

        std::cout << b[0] << ' ' << b[1] << ' ' << b[6] - b[0] - b[1] << std::endl;
    }

    return 0;
}
