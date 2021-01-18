// A. Zoning Restrictions Again

#include <iostream>
#include <algorithm>
#include <vector>


int main(){

    int n, h, m;
    std::cin >> n >> h >> m;

    std::vector<int> v(n, h);

    while (m--) {
        int l, r, x;
        std::cin >> l >> r >> x;
        for (int i = l-1; i < r; ++i) v[i] = std::min(v[i], x);
    }

    int profit = 0;
    for (auto el: v) profit += el * el;

    std::cout << profit << std::endl;

    return 0;
}
