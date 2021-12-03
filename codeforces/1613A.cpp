// A. Long Comparison

#include <iostream>


int main() {

    int t;
    std::cin >> t;

    while (t--) {

        double x1, x2;
        int p1, p2;
        std::cin >> x1 >> p1 >> x2 >> p2;

        // Editorial - https://codeforces.com/blog/entry/97467

        while (x1 >= 10) {
            x1 /= 10;
            ++p1;
        }
        while (x2 >= 10) {
            x2 /= 10;
            ++p2;
        }

        char ans;

        if (p1 > p2) {
            ans = '>';
        }
        else if (p1 < p2) {
            ans = '<';
        }
        else {
            if (x1 > x2) {
                ans = '>';
            }
            else if (x1 < x2) {
                ans = '<';
            }
            else {
                ans = '=';
            }
        }

        std::cout << ans << std::endl;
    }

    return 0;
}
