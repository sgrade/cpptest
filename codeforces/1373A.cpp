// 1373A - Donut Shops

#include <iostream>


int main() {

    int t;
    std::cin >> t;

    while (t--) {

        double a, b, c;
        std::cin >> a >> b >> c;

        double price_b = c / b;

        int ans[2] = {-1, -1};
        
        if (a <= price_b) {
            ans[0] = (int)(b - 1);
        }
        else {
            ans[0] = c / a > 1 ? 1 : -1;
            ans[1] = (int)b;
        }

        std::cout << ans[0] << ' ' << ans[1] << std::endl;

    }

    return 0;
}