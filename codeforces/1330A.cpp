// A. Dreamoon and Ranking Collection
// Wrong answer on test 1 

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>


int main() {

    int t;
    std::cin >> t;

    while (t--) {
        int n, x;
        std::cin >> n >> x;
        std::vector<int> a(std::max(n, x) + 1, 0);
        int tmp;
        for (int i = 0; i < n; ++i) {
            std::cin >> tmp;
            a[tmp-1] = 1;
        }

        int ans = 0;
        
        int i = 0;
        for (; x > 0; ++i) {
            if (i >= n) {
                i += x;
                break;
            }
            else if (a[i] == 0) {
                a[i] = 1;
                --x;
            }
        }

        if (i < n) {
            auto it = std::find(a.begin()+i+1, a.end(), 0);
            ans = std::distance(a.begin(), it);
        }
        else {
            ans = i + 1;
        }
        
        std::cout << ans << std::endl;
    }

    return 0;
}
