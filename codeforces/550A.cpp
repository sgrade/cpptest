// A. Two Substrings

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(){

    string s;
    getline(cin, s);

    bool ans = false;
    
    string s1 = "AB", s2 = "BA";
    int mn = 0, mx = 0;

    auto it1 = s.find(s1, mn);
    auto it2 = s.find(s2, mx);

    if (it1 != string::npos && it2 != string::npos)
    {
        mn = min(it1, it2);
        mx = max(it1, it2);

        if (mx - mn >= 2)
        {
            ans = true;
        }
        else
        {
            s1 = s.substr(mn, 2);
            s2 = s.substr(mx, 2);

            it2 = s.find(s2, mn + 2);
            if (it2 != string::npos)
            {
                ans = true;
            }
            else
            {
                it1 = s.find(s2);
                it2 = s.find(s1, it1 + 2);
                if (it2 != string::npos)
                {
                    ans = true;
                }
            }
        }
        
    }

    cout << (ans ? "YES\n": "NO\n");

    return 0;
}
