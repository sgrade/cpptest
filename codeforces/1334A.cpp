// A. Level Statistics

#include <iostream>


int main(){

    int t;
    std::cin >> t;

    while (t--) {

        int n;
        std::cin >> n;
        
        bool ans = true;

        int p, c;
        std::cin >> p >> c;
        if (p < c) ans = false;
        --n;

        int current_p, current_c;
        while (n--) {
            std::cin >> current_p >> current_c;
            if (current_p < p || current_c < c || current_p - p < current_c - c) {
                ans = false;
            }
            p = current_p;
            c = current_c;
        }

        std::cout << (ans ? "YES" : "NO") << std::endl;

    }

    return 0;
}
