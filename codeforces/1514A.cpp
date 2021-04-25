// A. Perfectly Imperfect Array

#include <iostream>
#include <set>


int main() {

    int t;
    std::cin >> t;

    std::set<int> dp;
    for (int i = 1; i < 10001; ++i) {
        dp.insert(i * i);
    }

    while (t--) {
        int n;
        std::cin >> n;

        int tmp;
        std::set<int> st;
        for (int i = 0; i < n; ++i) {
            std::cin >> tmp;
            st.insert(tmp);
        }

        bool ans = false;

        for (auto &el: st) {
            if (dp.find(el) == dp.end()) {
                ans = true;
                break;
            }
        }

        std::cout << (ans ? "YES" : "NO") << std::endl;
    }

    return 0;
}
