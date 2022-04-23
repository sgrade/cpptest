// B. I love AAAB

#include <iostream>
#include <string>

using namespace std;


bool check(const int &a, const int &b) {
    if (a < b) return false;
    if (b == 0) return false;
    return true;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        string s;
        cin >> s;

        bool ans = true;

        int n = s.size();

        if (n == 1 || s[0] == 'B' || s[n-1] == 'A') ans = false;

        else {
            int cnt_a = 0, cnt_b = 0;
            for (int i = 0; i < n; ) {
                while (i < n && s[i] == 'A') {
                    ++cnt_a;
                    ++i;
                }
                while (i < n && s[i] == 'B') {
                    ++cnt_b;
                    ++i;
                }
                ans = check(cnt_a, cnt_b);
                if (ans == false) break;
            }
        }
        
        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
