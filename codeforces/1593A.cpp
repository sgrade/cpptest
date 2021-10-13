// A. Elections

#include <iostream>

int main() {

    int t;
    std::cin >> t;

    while (t--) {

        int a, b, c;
        std::cin >> a >> b >> c;

        int A, B, C;
        A = std::max(b, c) + 1;
        B = std::max(a, c) + 1;
        C = std::max(a, b) + 1;

        A = A < a ? 0 : A - a;
        B = B < b ? 0 : B - b;
        C = C < c ? 0 : C - c;

        std::cout << A << ' ' << B << ' ' << C << '\n';
    }

    return 0;
}
