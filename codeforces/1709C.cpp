// C. Recover an RBS
// Not finished

#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int open, close;
vector<int> q;

void CountRBS (const string s) {
    string rbs = "";
    
    open = s.size() / 2;
    close = s.size() / 2;
    q.clear();

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') --open;
        else if (s[i] == ')') --close;
        else q.push_back(i);
    }
}

bool IsRBS(string &s) {
    stack<char> st;
    for (const char &c: s) {
        if (c == '(') {
            st.push('(');
        }
        else {
            if (st.empty() || st.top() == ')') {
                return false;
            }
            st.pop();
        }
    }
    if (st.empty()) {
        return true;
    }
    return false;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        string s;
        cin >> s;
        
        int n = s.size();

        // Editorial - https://codeforces.com/blog/entry/105164
                
        int cnt = 1;

        CountRBS(s);

        // Create RBS;
        // Idea is from the editorial
        for (int i = 0; i < q.size(); ++i) {
            if (i < open) {
                s[q[i]] = '(';
            }
            else {
                s[q[i]] = ')';
            }
        }

        if (open > 0 && close > 0) {
            swap(s[q[open - 1]], s[q[open]]);
            if (IsRBS(s)) {
                cnt = 2;
            }
        }

        cout << (cnt == 1 ? "YES\n" : "NO\n");
    }

    return 0;
}
