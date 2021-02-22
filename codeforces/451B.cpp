// B. Sort the Array

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &el: a) cin >> el;

    bool ans = false;
    int l = 0, r = 0;

    if (n == 1) {
        ans = true;
        l = 1;
        r = 1;
    }
    else {
        bool stop = false;
        int peaks = 0;
        for (int i = 1; !stop && i < n; ++i) {
            if (a[i-1] > a[i])
            {
                ++peaks;
                if (peaks > 2) {
                    break;
                }
                l = i-1;
                for (int j = i; j < n; ++j) {
                    if (a[j-1] < a[j]) 
                    {
                        ++peaks;
                        r = j;
                        i = j + 2;
                        break;
                    }
                }
                if (r == 0) {
                    r = n;
                    stop = true;
                }
            }
        }
        if (peaks <=2) {
            reverse(a.begin() + l, a.begin() + r);
            if (is_sorted(a.begin(), a.end())) 
            {
                ans = true;
            }
            // correction for 1-based indexing
            ++l;
            // correction for r is not required, because it is included in the range [l:r]
            
            // if it is sorted already
            if (peaks == 0) {
                r = 1;
            }
        }
    }

    std::cout << (ans ? "yes" : "no") << endl;
    if (ans) {
        std::cout << l << ' ' << r << endl;
    }

    return 0;
}
