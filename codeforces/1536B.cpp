// B. Prinzessin der Verurteilung

#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

// With default comparator it will be a, aa, ..., b, ba, ... (size doesn't matter)
// In the below comparator size does matter: it will be a, b, ..., aa, ... ba, ..
struct sComp {
    bool operator() (const string& a, const string& b) const
    {
        if (a.size() < b.size()) {
            return true;
        }
        return a < b;
    }
};

int main() {

    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    set<string, sComp> dp;
    // See in editorial why 3 levels only
    // Editorial - https://codeforces.com/blog/entry/91520
    for (int i = 0; i < 26; ++i) {
        string s1(1, alphabet[i]);
        dp.insert(s1);
        for (int j = 0; j < 26; ++j) {
            string s2(1, alphabet[j]);
            dp.insert(s1 + s2);
            for (int k = 0; k < 26; ++k) {
                string s3(1, alphabet[k]);
                dp.insert(s1 + s2 + s3);
            }
        }
    }

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        string s;
        getline(cin >> ws, s);

        for (auto &el: dp) {
            if (s.find(el) == string::npos) {
                cout << el << endl;
                break;
            }
        }
    }

    return 0;
}
