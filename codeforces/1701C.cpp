// C. Schedule Management

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


bool check (const vector<int>& p, const int & t) {
    long long free_time = 0, need_time = 0;
    for (int i = 1; i < p.size(); ++i) {
        if (p[i] < t) {
            free_time += (t - p[i]) / 2;
        }
        else {
            need_time += p[i] - t;
        }
    }
    return need_time <= free_time;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        vector<int> a(m);
        for (int &el: a) cin >> el;

        vector<int> p(n + 1);
        for (int i = 0; i < m; ++i) {
            ++p[a[i]];
        }
        sort(p.begin() + 1, p.end());

        int ans;

        int left = p[1], right = p[n] * 2;
        int mid;
        
        // Editorial - https://codeforces.com/blog/entry/104671

        while (left <= right) {
            mid = left + (right - left)/2;
            if (check(p, mid)) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
       
        cout << ans << '\n';
    }

    return 0;
}
