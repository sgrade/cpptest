// A. Sushi for Two

#include <iostream>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> t(n);
    for (auto &el: t) {
        cin >> el;
        --el;
    }

    vector<int> cnt(2);
    int cur = t[0], prev = -1;
    cnt[cur] = 1;

    int ans = 0;

    for (int i = 1; i < n; ++i) {

        if (t[i] == cur) {
            ++cnt[cur];
        }

        else {
            prev = cur;
            cur = t[i];
            cnt[cur] = 1;
        }

        ans = max(ans, min(cnt[0], cnt[1]));
    }

    cout << ans * 2 << '\n';

    return 0;
}
