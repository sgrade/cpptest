// B. Same Parity Summands

#include <iostream>
#include <vector>


int main(){

    int t;
    std::cin >> t;

    while (t--) {

        int n, k;
        std::cin >> n >> k;

        bool ans = false;

        std::vector<int> output;

        if (k == n) {
            ans = true;
            while (k--) output.push_back(1);
        }
        else if (k < n) {
            if (n % 2 == 0) {
                if (k % 2 == 0) {
                    ans = true;
                    for (int i = 1; i < k; ++i) output.push_back(1);
                    output.push_back(n - (k - 1));
                }
                //  k % 2 != 0
                else {
                    if (k * 2 <= n) {
                        ans = true;
                        for (int i = 1; i < k; ++i) output.push_back(2);
                        output.push_back(n - (k - 1) * 2);
                    }
                }
            }
            //  n % 2 != 0
            else {
                if (k % 2 != 0) {
                    ans = true;
                    for (int i = 1; i < k; ++i) output.push_back(1);
                    output.push_back(n - (k - 1));
                }
            }
        }
        std::cout << (ans ? "YES" : "NO") << std::endl;
        if (ans) {
            for (auto el: output) std::cout << el << ' ';
            std::cout << std::endl;
        }
    }

    return 0;
}
