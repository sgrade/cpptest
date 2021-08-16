// C. Penalty

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ans, current_ans;
int score_a, score_b;
int attempts_left_a, attempts_left_b;

bool check (int i) {
    if (score_a > score_b + attempts_left_b || score_b > score_a + attempts_left_a) {
        current_ans = min(current_ans, i+1 + i);
        return true;
    }
    else return false;
}


int main() {

    int t;
    cin >> t;

    while (t--) {

        string s;
        cin >> s;

        // Editorial - https://codeforces.com/blog/entry/93105

        // Two teams: a, b
        vector<char> a, b;
        for (int i = 0; i < 10; i += 2) {
            a.push_back(s[i]);
        }
        for (int i = 1; i < 10; i += 2) {
            b.push_back(s[i]);
        }

        ans = 10;

        // '?' for team_a = 1, for team_b = 0
        score_a = 0, score_b = 0;
        attempts_left_a = 5, attempts_left_b = 5;
        current_ans = 10;
        for (int i = 0; i < 5; ++i) {
            score_a += a[i] != '0';
            attempts_left_a -= 1;
            if (check(i)) break;

            score_b += b[i] == '1';
            attempts_left_b -= 1;
            if (check(i)) {
                ++current_ans;
                break;
            }
        }
        ans = min(current_ans, ans);

        // '?' for team_a = 0, for team_b = 1
        score_a = 0, score_b = 0;
        attempts_left_a = 5, attempts_left_b = 5;
        current_ans = 10;
        for (int i = 0; i < 5; ++i) {
            score_a += a[i] == '1';
            attempts_left_a -= 1;
            if (check(i)) break;

            score_b += b[i] != '0';
            attempts_left_b -= 1;
            if (check(i)) {
                ++current_ans;
                break;
            }
        }
        ans = min(current_ans, ans);

        cout << ans << endl;
        
    }

    return 0;
}
