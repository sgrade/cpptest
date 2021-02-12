// A. The King's Race

#include <iostream>
#include <algorithm>


int main(){

    long long n;
    std::cin >> n;

    long long x, y;
    std::cin >> x >> y;

    long long w = std::max(x, y) - 1;

    long long b = n - std::min(x, y);

    std::cout << (b < w ? "Black": "White") << std::endl;

    return 0;
}
