// C. Concatenation of Arrays

#include <bits/stdc++.h>

using namespace std;


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        vector<pair<int, int>> v(n);
        for (pair<int, int>& p: v)
            cin >> p.first >> p.second;
        sort(v.begin(), v.end(), [](pair<int, int>& p1, pair<int, int>& p2){
            int sum1 = p1.first + p1.second, sum2 = p2.first + p2.second;
            if (sum1 < sum2)
                return true;
            else if (sum2 < sum1)
                return false;
            return p1.first < p2.first;
        });

        for (int i = 0; i < n; ++i)
            cout << v[i].first << ' ' << v[i].second << ' ';
        cout << endl;
    }

    return 0;
}
