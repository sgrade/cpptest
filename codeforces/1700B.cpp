// B. Palindromic Numbers

#include <iostream>
#include <vector>
#include <string>

using namespace std;


void to_999 (vector<int>& a, vector<int>& ans, const int& n) {
    for (int i = 0; i < n; ++i) {
        ans[i] = 9 - a[i];
    }
}

void to_111 (vector<int>& a, vector<int>& ans, const int& n) {
    int have, need, carry = 0;
    for (int i = n - 1; i >= 0; --i) {
        have = a[i] + carry;
        need = 1;
        if (have <= need) {
            ans[i] = need - have;
            carry = 0;
        }
        else {
            ans[i] = 11 - have;
            carry = 1;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        string s;
        cin >> s;

        n = s.size();

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = s[i] - '0';
        }

        vector<int> ans(n);

        if(a[0] != 9) {
            to_999(a, ans, n);
        }
        else {
            to_111(a, ans, n);
        }
        
        for (int i = 0; i < n; ++i) {
            cout << ans[i];
        }
        cout << '\n';
    }

    return 0;
}
