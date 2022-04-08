// C. Bracket Sequence Deletion

#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;


bool isPalindrome (vector<char> &p)
{
    int n = size(p);
    for (int i = 0; i < size(p) / 2; ++i) {
        if (p[i] != p[n-i-1]) return false;
    }
    return true;
}


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        string s;
        cin >> s;

        int c = 0, r;

        stack<char> reg;
        vector<char> pal;

        int chars = 0;

        for (int i = 0; i < n; ++i) {

            ++chars;
            
            // If regular
            if (chars % 2 != 0)
            {
                reg.push(s[i]);
            }
            else
            {
                if (reg.top() == '(' && s[i] == ')')
                {
                    reg.pop();
                }
                else
                {
                    reg.push(s[i]);
                }
            }

            // If palindrome
            pal.push_back(s[i]);

            // If the prefix is good
            if ( (chars > 1) && ( reg.empty() || isPalindrome(pal) ) ) {
                ++c;
                chars = 0;
                reg = stack<char>();
                pal.erase(pal.begin(), pal.end());
            }
        }

        r = max(size(reg), size(pal));

        cout << c << ' ' << r << '\n';
    }

    return 0;
}
