// A. Lex String
 
#include <iostream>
#include <algorithm>
#include <string>
 
using namespace std;
 
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
 
    while (t--) {
 
        int n, m, k;
        cin >> n >> m >> k;
 
        string a, b;
        cin >> a >> b;
 
        int idx_a = 0, idx_b = 0;
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
 
        string ans;
 
        // Idea from https://codeforces.com/contest/1689/submission/160093454
        // Positive cur is for a, negative is for b
        int cur = 0;
        
        while (idx_a < n && idx_b < m) {
            bool ok_a = cur < k;
            bool ok_b = cur > -k;
            if (ok_a && (!ok_b || a[idx_a] < b[idx_b])) {
                ans += a[idx_a++];
                // If we take a char from a, we reset number of b moves to 0
                cur = max(0, cur) + 1;
            }
            else {
                ans += b[idx_b++];
                // If we take a char from b, we reset number of a moves to 0
                cur = min(0, cur) - 1;
            }
        }
 
        for (char &ch: ans) {
            cout << ch;
        }
        cout << '\n';
    }
 
    return 0;
}
