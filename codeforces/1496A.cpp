// A - Split it!

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        string s;
        getline(cin >> ws, s);

        bool ans = false;

        if (k == 0)
            ans = true;
        else
        {
            // Editorial - https://codeforces.com/blog/entry/88533
            if (2 * k != n)
            {
                string s_reversed = s;
                reverse(s_reversed.begin(), s_reversed.end());
                
                if (s.substr(0, k) == s_reversed.substr(0, k))
                {
                    ans = true;
                }
            }
        }

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
