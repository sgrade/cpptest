// C. Exams

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int n;
    cin >> n;

    int a, b;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        v[i] = pair<int, int>(a, b);
    }
    sort(v.begin(), v.end());

    int ans = 0;
    for (auto p: v) {
        ans = max(ans, p.second);
        if (ans != p.second) ans = p.first;
    }

    cout << ans << endl;

    return 0;
}
