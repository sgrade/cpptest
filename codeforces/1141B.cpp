// B. Maximal Continuous Rest

#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    int n;
    std::cin >> n;

    std::vector<int> a(n);

    for (auto &el: a) {
        std::cin >> el;
    }

    int ans = 0;

    std::vector<int>::iterator it1, it2;
    
    it1 = std::find(begin(a), end(a), 1);    
    do {
        auto it2 = std::find(it1, end(a), 0);
        int d = std::distance(it1, it2);
        ans = std::max(ans, d);

        it1 = std::find(it2, end(a), 1);

    } while (it1 != end(a) && it2 != a.end());

    it1 = std::find(begin(a), end(a), 0);
    auto rit = std::find(rbegin(a), rend(a), 0);
    if (it1 != end(a) && rit != rend(a)) {
        int d = std::distance(begin(a), it1);
        d += n - std::distance(begin(a), rit.base());
        ans = std::max(ans, d);
    }
    
    std::cout << ans << std::endl;

    return 0;
}
