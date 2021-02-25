// B. Books

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int n, t;
    cin >> n >> t;

    vector<int> a(n);
    for (auto &el: a) cin >> el;

    int ans = 0;

    int l = 0, r = 0, current_ans = 0, time = 0;

    while (r < n) 
    {       
        l = max(l, r);
        while (time <= t && l <= n) {
            time += *(a.rbegin() + l);
            ++l;
        }
        current_ans = l - r - 1;
        ans = max(ans, current_ans);

        --l;
        time -= *(a.rbegin() + l);

        if (l != r) time -= *(a.rbegin() + r);
        ++r;

        if (n - r < ans) break;
    }

    cout << ans << endl;

    return 0;
}
