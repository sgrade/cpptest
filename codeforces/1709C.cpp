// C. Recover an RBS
// Time limit exceeded on test 3

#include <iostream>
#include <string>
#include <stack>

using namespace std;


void backtrack(string &s, const int &n, int &cnt, int i, stack<char> st) {
    if (cnt > 1) 
        return;
    
    if (i == n) {
        if (st.empty()) {
            ++cnt;
        }
        return;
    }

    if (s[i] == '(') {
        st.push('(');
        backtrack(s, n, cnt, i + 1, st);
    }
    else if (s[i] == ')') {
        if (st.empty() || st.top() == ')') {
            st.push(')');
        }
        else {
            st.pop();
        }
        backtrack(s, n, cnt, i + 1, st);
    }
    else {  // s[i] == '?'
        s[i] = '(';
        backtrack(s, n, cnt, i, st);

        s[i] = ')';
        backtrack(s, n, cnt, i, st);

        s[i] = '?';
    }
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
                
        int cnt = 0;

        stack<char> st;

        backtrack(s, n, cnt, 0, st);

        cout << (cnt == 1 ? "YES\n" : "NO\n");
    }

    return 0;
}
