// A. Regular Bracket Sequences

#include <iostream>


int main() {

    int t;
    std::cin >> t;

    while (t--) {

        int n;
        std::cin >> n;
        
        // Idea - https://codeforces.com/contest/1574/submission/129341923
        
        for (int i = 1; i < n+1; ++i) {
            for (int j = 0; j < i; ++j) {
                std::cout << '(';
            }
            for (int j = 0; j < i; ++j) {
                std::cout << ')';
            }
            for (int j = i; j < n; ++j) {
                std::cout << "()";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
