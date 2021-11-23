// A. Distance

#include <iostream>


int main() {

    int t;
    std::cin >> t;

    while (t--) {

        int x, y;
        std::cin >> x >> y;

        // Explanation - https://www.youtube.com/watch?v=qSPFa3Fj4jU

        int z = x + y;

        int cx = -1, cy = -1;
        
        if (!(z & 1)) {
            z /= 2;
            if (x > y) {
                cx = z;
                cy = 0;
            }
            else {
                cx = 0;
                cy = z;
            }
        }

        std::cout << cx << ' ' << cy << std::endl;

    }

    return 0;
}
