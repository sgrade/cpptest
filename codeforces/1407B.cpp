// B. Big Vova
// NOT FINISHED: wrong answer Participant's answer is worse (test case 51)

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <limits>

using namespace std;


int gcd (int a, int b) {
    if (b == 0) return a;
    return gcd (b, a % b);
}


int main(){

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &el: a) cin >> el;
        sort(a.begin(), a.end(), greater<int>());

        vector<int> output;
        vector<bool> chosen(n, false);
        output.push_back(a[0]);
        chosen[0] = true;
        
        for (int i = 1; i < n; ++i) {
            int max_gcd = 0;
            int max_j;
            for (int j = 1; j < n && max_gcd < a[j]; ++j) {
                if (chosen[j]) continue;
                int cur_gcd = numeric_limits<int>::max();
                for (int k = 0; k < output.size(); ++k) {
                    cur_gcd = min(cur_gcd, gcd(output[k], a[j]));
                }
                if (cur_gcd > max_gcd) {
                    max_gcd = cur_gcd;
                    max_j = j;
                }
            }

            output.push_back(a[max_j]);
            chosen[max_j] = true;

        }

        for (auto el: output) cout << el << ' ';
        cout << endl;
    }

    return 0;
}
