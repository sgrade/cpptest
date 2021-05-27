// A. Juicer

#include <iostream>
#include <vector>


int main() {

    int n, b, d;
    std::cin >> n >> b >> d;

    int ans = 0;

    int tmp, sm = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> tmp;
        if (tmp <= b) {
            sm += tmp;
            if (sm > d) {
                sm = 0;
                ++ans;
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
