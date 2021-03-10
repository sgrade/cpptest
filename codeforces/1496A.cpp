// A - Split it!
// Wrong answer on pretest 2

#include <iostream>
#include <vector>
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
            if (n % 2 != 0)
            {
                string s_reversed = s;
                reverse(s_reversed.begin(), s_reversed.end());
                
                if (s.substr(n / 2) == s_reversed.substr(n / 2))
                {
                    ans = true;
                }
            }
        }

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
