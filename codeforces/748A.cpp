// A. Santa Claus and a Place in a Class

#include <iostream>


int main(){

    int n, m, k;
    std::cin >> n >> m >> k;

    int r = k / (2 * m);
    if (k % (2 * m) != 0) ++r;

    int d = (k - (r - 1) * 2 * m) / 2;
    if ((k - (r - 1) * 2 * m) % 2 != 0) ++d;

    char s = k % 2 != 0 ? 'L' : 'R';

    std::cout << r << ' ' << d << ' ' << s << std::endl;

    return 0;
}
