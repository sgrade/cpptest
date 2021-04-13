// C. A-B Palindrome

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int a, b;
        cin >> a >> b;

        string s;
        getline(cin >> ws, s);

        int n = s.size();
        
        bool ans = true;
        
        vector<char> v(n);
        int pairs = 0;
        vector<int> pair_idxs;
        for (int i = 0; i < n / 2; ++i) {  
            
            if (s[i] == '?' && s[n-i-1] == '?') {
                ++pairs;
                pair_idxs.push_back(i);
                continue;
            }
            
            else if (s[i] != '?' && s[n-i-1] != '?') {

                if (s[i] != s[n-i-1]) {
                    ans = false;
                    break;
                }
                else {
                    v[i] = s[i];
                    v[n-i-1] = s[i];
                }
            }
            
            // s[i] != '?' || s[n-i-1] != '?'
            else {

                if (s[i] != '?') {
                    v[i] = s[i];
                    v[n-i-1] = s[i];
                }
                else {
                    v[i] = s[n-i-1];
                    v[n-i-1] = s[n-i-1];
                }
            }

            if (v[i] == '0') {
                a -= 2;
            }
            else if (v[i] == '1') {
                b -= 2;
            }
        }

        if (n % 2 != 0) {
            if (s[n/2] == '0') {
                v[n/2] = '0';
                --a;
            }
            else if (s[n/2] == '1') {
                v[n/2] = '1';
                --b;
            }
            // Editorial - https://codeforces.com/blog/entry/89535
            else {
                if (a % 2 != 0) {
                    v[n/2] = '0';
                    --a;
                }
                else if (b % 2 != 0) {
                    v[n/2] = '1';
                    --b;
                }
                else {
                    ans = false;
                }
            }
        }
        
        if (ans != false && !(a == 0 && b == 0 && pairs == 0)) {
            if (a % 2 != 0 || b % 2 != 0) {
                ans = false;
            }
            else if (pairs * 2 != a + b) {
                ans = false;
            }
            else {
                int idx = 0, i;
                for (; a > 1 && idx < pair_idxs.size(); ++idx) {
                    a -= 2;
                    i = pair_idxs[idx];
                    v[i] = '0';
                    v[n-i-1] = '0';
                }
                for (; idx < pair_idxs.size(); ++idx) {
                    b -= 2;
                    i = pair_idxs[idx];
                    v[i] = '1';
                    v[n-i-1] = '1';
                }
            }
        }

        if (a != 0 || b != 0) {
            ans = false;
        }

        if (ans) {
            for (auto el: v) {
                cout << el;
            }
            cout << endl;
        }
        else {
            cout << "-1" << endl;
        }
    }

    return 0;
}
