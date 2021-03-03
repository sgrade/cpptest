// B. Subsequence Hate

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        getline(cin >> ws, s);

        int ans;
        
        if (s.size() < 3)
        {
            ans = 0;
        }

        else
        {
            int zeroes = count(s.begin(), s.end(), '0');
            int ones = s.size() - zeroes;

            ans = min(zeroes, ones);

            if (ans != 0)
            {
                // Editorial - https://codeforces.com/blog/entry/78202
                int pref0 = 0, suf0 = zeroes, pref1 = 0, suf1 = ones;

                for (auto &ch: s)
                {
                    if (ch == '0')
                    {
                        ++pref0;
                        --suf0;
                    }
                    else{
                        ++pref1;
                        --suf1;
                    }

                    // Make string 000111
                    ans = min(ans, pref1 + suf0);
                    // Make string 111000
                    ans = min(ans, pref0 + suf1);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
