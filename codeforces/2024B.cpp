// B. Buying Lemonade

#include <bits/stdc++.h>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int& el: a)
            cin >> el;

        sort(a.begin(), a.end());
        long long ans = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            long long sum_of_level = 1LL * (a[i] - (i == 0 ? 0 : a[i - 1])) * (n - i);
            if (sum + sum_of_level  < k)
                ans += sum_of_level + 1;
            else {
                long long need = k - sum;
                ans += need;
                break;
            }
            sum += sum_of_level;
        }

        cout << ans << endl;
    }

    return 0;
}
