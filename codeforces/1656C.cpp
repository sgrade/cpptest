// C. Make Equal With Mod

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) 
    {
        int n;
        cin >> n;

        set<int> a;
        int tmp;
        for (int i = 0; i < n; ++i) 
        {
            cin >> tmp;
            a.insert(tmp);
        }

        bool ans = true;

        if (a.find(1) != a.end() && a.size() > 1) 
        {
            // Editorial - https://codeforces.com/blog/entry/101211
            set<int>::iterator it = a.begin();
            int prev = *it, cur;
            while (it++ != a.end()) 
            {
                cur = *it;
                if (cur - prev == 1) ans = false;
                prev = cur;
            }
        }

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
