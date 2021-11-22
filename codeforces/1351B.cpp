// B. Square?

#include <iostream>


int main() {

    int t;
    std::cin >> t;

    while (t--) {

        int a1, b1, a2, b2;
        std::cin >> a1 >> b1 >> a2 >> b2;

        if (a1 > b1) {
            std::swap(a1, b1);
        }
        if (a2 > b2) {
            std::swap(a2, b2);
        }

        bool ans = true;

        int a = a1 + a2;
        if (a != b1 || a != b2) {
            ans = false;
        }

        std::cout << (ans ? "Yes" : "No") << std::endl;

    }

    return 0;
}
