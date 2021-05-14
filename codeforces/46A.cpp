// A. Ball Game

#include <iostream>

using namespace std;


int main() {

    int n;
    cin >> n;

    int j = 0, increment = 1;
    for (int i = 1; i < n; ++i) {
        j += increment;
        std::cout << j % n + 1 << ' ';
        ++increment;
    }
    std::cout << endl;

    return 0;
}
