// A. Dreamoon and Ranking Collection

#include <iostream>
#include <set>


int main() {

    int t;
    std::cin >> t;

    while (t--) {
        int n, x;
        std::cin >> n >> x;
        std::set<int> a;
        int tmp;
        for (int i = 0; i < n; ++i) {
            std::cin >> tmp;
            a.insert(tmp);
        }

        int ans = 0;
        
        std::set<int>::iterator it;
        while (x > 0) {
            ++ans;
            it = a.find(ans);
            if (it == a.end()){
                --x;
            }
        }
        tmp = ans + 1;
        while (true) {
            it = a.find(tmp);
            if (it == a.end()){
                break;
            }
            ++tmp;
            ++ans;
        }

        std::cout << ans << std::endl;
    }   

    return 0;
}
