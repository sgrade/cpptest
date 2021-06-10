// A. Three Friends

#include <iostream>
#include <set>


int main() {

    int q;
    std::cin >> q;

    while (q--) {

        std::multiset<int> st;
        int tmp;
        for (int i = 0; i < 3; ++i) {
            std::cin >> tmp;
            st.insert(tmp);
        }
        
        int a, b, c;
        std::multiset<int>::iterator it = begin(st);
        a = *it;
        ++it;
        b = *it;
        ++it;
        c = *it;

        int ans = c - a;
        ans = std::max(ans - 2, 0);

        if (ans > 0) {
            ans += (b - (a + 1)) + ((c - 1) - b);
        }

        std::cout << ans << std::endl;

    }

    return 0;
}
