// A. IQ test

#include <iostream>


int main(){

    int n;
    std::cin >> n;

    int x;
    std::cin >> x;
    bool parity = x % 2;

    int ans = 1;
    
    for (int i = 2; i <= n; ++i) {
        std::cin >> x;
        if (x % 2 != parity) {
            if (i == 2) {
                int tmp;
                std::cin >> tmp;
                if (tmp % 2 != x % 2) ans = 2;
                break;
            }
            else {
                ans = i;
                break;
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
