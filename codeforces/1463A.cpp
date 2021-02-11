// A. Dungeon

#include <iostream>
#include <algorithm>


int main(){

    int t;
    std::cin >> t;

    while (t--) {
        int a, b, c;
        std::cin >> a >> b >> c;

        bool ans = false;

        int x = (a + b + c) / 9;
        if (std::min({a, b, c}) >= x) {
            int y = (a + b + c) % 9;
            if (y == 0) ans = true;
        }

        std::cout << (ans ? "YES" : "NO") << std::endl;
    }

    return 0;
}
