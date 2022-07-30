// D. The Clock

#include <iostream>
#include <string>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        string s;
        cin >> s;

        int x;
        cin >> x;

        // Idea - https://codeforces.com/contest/1692/submission/160546661

        int start_time = (s[0] - '0') * (60 * 10) + (s[1] - '0') * 60 + 
            (s[3] - '0') * 10 + (s[4] - '0');

        int current_time = start_time;
        int t0, t1, t3, t4;
        
        int ans = 0;

        while (true) {
            current_time += x;
            current_time %= 1440;
            t0 = current_time / (60 * 10);
            t4 = current_time % 10;
            t1 = current_time / 60 % 10;
            t3 = current_time % 60 / 10;
            if (t0 == t4 && t1 == t3) {
                ++ans;
            }
            if (current_time == start_time) {
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
