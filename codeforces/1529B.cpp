// B. Sifid and Strange Subsequences

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        int ans = 0;

        int tmp;
        vector<int> a;
        set<int> positives;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            if (tmp <= 0) {
                a.push_back(tmp);
                ++ans;
            }
            else {
                positives.insert(tmp);
            }
        }

        if (!positives.empty()) {
            int mn = *positives.begin();
            ++ans;
            sort(begin(a), end(a));
            for (int i = 1; i < a.size(); ++i) {
                if (abs(a[i-1] - a[i]) < mn) {
                    --ans;
                    break;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
