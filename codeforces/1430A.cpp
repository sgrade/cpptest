// A. Number of Apartments

#include <iostream>


int main(){

    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        if (n == 1 || n == 2 || n == 4){
            std::cout << "-1\n";
        }
        else if (n % 3 == 0) {
            std::cout << n / 3 << " 0 0\n";
        }
        else if (n % 3 == 1) {
            std::cout << n / 3 - 2 << " 0 1\n";
        }
        else if (n % 3 == 2) {
            std::cout << n / 3 - 1 << " 1 0\n";
        }
    }

    return 0;
}
