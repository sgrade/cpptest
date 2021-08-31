// A. Forgetting Things

#include <iostream>


int main() {

    int da, db;
    std::cin >> da >> db;
    
    if (da == db) {
        std::cout << da << 1 << ' ' << db << 2 << std::endl;
    }
    else if (da + 1 == db) {
        std::cout << da << ' ' << db << std::endl;
    }
    else if (da == 9 && db == 1) {
        std::cout << 9 << ' ' << 10 << std::endl;
    }
    // db - da > 1
    else {
        std::cout << -1 << std::endl;
    }

    return 0;
}
