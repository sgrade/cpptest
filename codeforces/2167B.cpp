// B. Your Name
// https://codeforces.com/contest/2167/problem/B

#include <bits/stdc++.h>

using namespace std;


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        string s1, s2;
        cin >> s1 >> s2;
        
        vector<int> count1(26, 0), count2(26, 0);
        for (char c : s1) {
            count1[c - 'a']++;
        }
        for (char c : s2) {
            count2[c - 'a']++;
        }

        bool ans = true;
        for (int i = 0; i < 26; ++i) {
            if (count1[i] != count2[i]) {
                ans = false;
                break;
            }
        }
        cout << (ans ? "YES" : "NO") << endl;
    }

    return 0;
}
 