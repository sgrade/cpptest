// A. Doremy's Paint 3

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        unordered_map<int, int> counter;
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            ++counter[tmp];
        }
        bool ans = false;
        if (counter.size() == 1)
            ans = true;
        else if (counter.size() == 2) {
            vector<int> x(2);
            auto it = counter.begin();
            int cnt1 = it->second;
            ++it;
            int cnt2 = it->second;
            if (abs(cnt1 - cnt2) < 2)
                ans = true;
        }
        cout << (ans ? "Yes" : "No") << "\n";
    }

    return 0;
}
