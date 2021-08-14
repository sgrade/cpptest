// C. Penalty

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        string s;
        cin >> s;

        // Editorial - https://codeforces.com/blog/entry/93105

        vector<char> a, b;
        for (int i = 0; i < 10; i += 2) {
            a.push_back(s[i]);
        }
        for (int i = 1; i < 10; i += 2) {
            b.push_back(s[i]);
        }

        int ans = 10;
        
        int score_a, score_b;
        int attempts_left_a, attempts_left_b;

        // '?' for team_a = 1, for team_b = 0
        score_a = 0, score_b = 0;
        attempts_left_a = 5, attempts_left_b = 5;
        for (int i = 0; i < 5; ++i) {
            score_a += a[i] != '0';
            attempts_left_a -= 1;
            if (score_a > score_b + attempts_left_b || score_b > score_a + attempts_left_a) {
                ans = min(ans, i+1 + i);
                break;
            } 

            score_b += b[i] == '1';
            attempts_left_b -= 1;
            if (score_a > score_b + attempts_left_b || score_b > score_a + attempts_left_a) {
                ans = min(ans, i+1 + i+1);
                break;
            }
        }

        // '?' for team_a = 0, for team_b = 1
        score_a = 0, score_b = 0;
        attempts_left_a = 5, attempts_left_b = 5;
        for (int i = 0; i < 5; ++i) {
            score_a += a[i] == '1';
            attempts_left_a -= 1;
            if (score_b > score_a + attempts_left_a || score_a > score_b + attempts_left_b) {
                ans = min(ans, i+1 + i);
                break;
            }

            score_b += b[i] != '0';
            attempts_left_b -= 1;
            if (score_b > score_a + attempts_left_a || score_a > score_b + attempts_left_b) {
                ans = min(ans, i+1 + i+1);
                break;
            }
        }

        cout << ans << endl;
        
    }

    return 0;
}
