// A. Romaji

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;


int main() {

    string s;
    cin >> s;

    unordered_set<char> st = {'a', 'o', 'u', 'i', 'e'};

    int n = s.size();

    bool ans = true;

    if (s[n-1] != 'n' && st.find(s[n - 1]) == st.end()) {
        ans = false;
    }

    if (ans != false) {
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] != 'n' && st.find(s[i]) == st.end()) {
                if (st.find(s[i+1]) == st.end()) {
                    ans = false;
                    break;
                }
            }
        }
    }
    
    cout << (ans ? "YES\n" : "NO\n");

    return 0;
}
