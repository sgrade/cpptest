// C. Pursuit
// Test: #2, time: 15 ms., memory: 4200 KB, exit code: 0, checker exit code: 1, verdict: WRONG_ANSWER
// wrong answer 70th numbers differ - expected: '1', found: '2'

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (auto &el: a) {
            cin >> el;
        }
        for (auto &el: b) {
            cin >> el;
        }

        sort(begin(a), end(a));
        sort(begin(b), end(b));

        int k = n;
        int k4 = k / 4;

        int my_score, his_score;
        my_score = accumulate(begin(a) + k4, end(a), 0);
        his_score = accumulate(begin(b) + k4, end(b), 0);

        int bi = k4;
        while (my_score < his_score) {
            ++k;

            // My score
            my_score += 100;
            if (k / 4 != k4) {
                k4 = k / 4;

                if (k4 < n){
                    my_score -= *(begin(a) + k4);
                }

                // Don't need to adjust his score because number of excluded items increased by 1
                continue;
            }

            // His score
            --bi;
            if (bi >= 0) {
                his_score += *(begin(b) + bi);
            }
        }

        int ans = k - n;
        cout << ans << endl;

    }
    return 0;
}
