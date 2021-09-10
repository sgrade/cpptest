// C. Pursuit

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n), b(n);
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            a[i] = tmp;
        }
        sort(begin(a), end(a));
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            b[i] = tmp; 
        }
        sort(begin(b), end(b));

        int score_a, score_b;
        int skipped = n / 4;
        score_a = accumulate(begin(a)+skipped, end(a), 0);
        score_b = accumulate(begin(b)+skipped, end(b), 0);

        // Idea - https://codeforces.com/contest/1544/submission/122787118
        
        int ans = 0;

        int idx_a = skipped;
        int idx_b = skipped - 1;

        int i = n % 4;
        
        while (score_a < score_b) {
            ++ans;
            ++i;
            score_a += 100;
            if (i == 4) {
                i = 0;
                score_a -= a[idx_a++];
            }
            else if (idx_b > -1) {
                score_b += b[idx_b--];
            }
        }

        cout << ans << endl;

    }

    return 0;
}
