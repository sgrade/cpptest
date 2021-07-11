// A. AquaMoon and Two Arrays

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

        int ans = -1;
        vector<vector<int>> output;

        int sum_a = accumulate(begin(a), end(a), 0);
        int sum_b = accumulate(begin(b), end(b), 0);

        if (sum_a == sum_b) {
            vector<int> differences(n);
            for (int i = 0; i < n; ++i) {
                differences[i] = a[i] - b[i];
            }

            vector<int> cur(2); 
            int j;

            for (int i = 0; i < n; ++i) {
                for (j = i+1; j < n; ++j) {
                    if (differences[i] == 0) {
                        break;
                    }
                    if (differences[j] == 0) {
                        continue;
                    }

                    // Sign is different?
                    int ddd = differences[i] + differences[j];
                    if ((differences[i] > 0 && differences[j] < 0) || (differences[i] < 0 && differences[j] > 0)) {
                        int d = min(abs(differences[i]), abs(differences[j]));
                        if (differences[i] > 0) {
                            differences[i] -= d;
                            differences[j] += d;
                            cur[0] = i+1;
                            cur[1] = j+1;
                        }
                        else {
                            differences[i] += d;
                            differences[j] -= d;
                            cur[0] = j+1;
                            cur[1] = i+1;
                        }
                    
                        for (int k = 0; k < d; ++k) {
                            output.push_back(cur);
                        }
                    }
                }
            }

            ans = output.size();

        }

        cout << ans << endl;

        if (ans > 0) {
            for (auto &v: output) {
                cout << v[0] <<' ' << v[1] << endl;
            }
        }
    }

    return 0;
}
