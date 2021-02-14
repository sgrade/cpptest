// C. Ping-pong

#include <iostream>


int main(){

    int t;
    std::cin >> t;

    while (t--) {
        int x, y;
        std::cin >> x >> y;

        std::cout << x - 1 << ' ' << y << std::endl;
    }

    return 0;
}
