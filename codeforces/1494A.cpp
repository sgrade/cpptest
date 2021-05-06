// A. ABC String

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        string s;
        getline(cin >> ws, s);

        int n = s.size();

        bool ans = true;

        char a = s[0], b = s[n-1], c;
        
        if (a == b) {
            ans = false;
        }

        else {
            int num_of_a = 0, num_of_b = 0, num_of_c = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] == a) {
                    ++num_of_a;
                }
                else if (s[i] == b) {
                    ++num_of_b;
                }
                else {
                    ++ num_of_c;
                }
            }

            if (num_of_a == num_of_b) {
                if (num_of_c != 0) {
                    ans = false;
                }
            }
            else {
                if (num_of_a > num_of_b) {
                    c = b;
                }
                else {
                    c = a;
                }
            }


            stack<char> st;
            st.push(a);
            for (int i = 1; i < n; ++i) {
                if (s[i] == a) {
                    st.push(a);
                }
                else if (s[i] == b) {
                    if (!st.empty()) {
                        st.pop();
                    }
                    else {
                        ans = false;
                        break;
                    }
                }
                // s[i] == c
                else {
                    if (c == a) {
                        st.push(a);
                    }
                    else if (c == b) {
                        if (!st.empty()) {
                            st.pop();
                        }
                        else {
                            ans = false;
                            break;
                        }
                    }
                }
            }
            if (!st.empty()) {
                ans = false;
            }
        }
        
        cout << (ans ? "YES" : "NO") << endl;
    }
    

    return 0;
}
