// B. Kefa and Company

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int n, d;
    cin >> n >> d;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());

    // Idea - https://www.youtube.com/watch?v=fkG_mF-55Rw
    unsigned long long ans = 0ULL, current_ans = 0ULL;
    int i = 0, j = 0;
    while (j < n) {
        while (j < n && v[j].first - v[i].first < d) {
            current_ans += v[j].second;
            ++j;
        }
        ans = max(ans, current_ans);
        current_ans -= v[i].second;
        ++i;
    }

    std::cout << ans << endl;

    return 0;
}
