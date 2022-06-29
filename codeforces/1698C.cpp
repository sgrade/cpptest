// C. 3SUM Closure
// Time limit exceeded on pretest 3

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        bool ans = true;

        vector<long long> A;
        unordered_set<long long> a;
        int neg = 0, pos = 0, zer = 0;
        long long tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            // Editorial - https://codeforces.com/blog/entry/104310
            if (tmp < 0) {
                ++neg;
            }
            else if (tmp > 0) {
                ++pos;
            }
            else {
                if (zer == 3) continue;
                ++zer;
            }
            if (neg > 2 || pos > 2) {
                ans = false;
            }
            else {
                A.push_back(tmp);
                a.insert(tmp);
            }
        }

        n = A.size();
        long long x;
        sort(A.begin(), A.end());
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    x = A[i] + A[j] + A[k];
                    if (a.find(x) == a.end()) {
                        ans = false;
                        goto ANS;
                    }
                }
            }
        }
        
        ANS:
        cout << (ans ? "YES\n" : "NO\n");

    }

    return 0;
}
