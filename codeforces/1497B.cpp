// B. M-arrays
// Time limit exceeded on pretest 2

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int tmp;
        map<int, int> mp;
        for (int i = 0; i < n; ++i)
        {
            cin >> tmp;
            ++mp[tmp];
        }

        int ans = 0;

        if (n == 1)
        {
            ans = 1;
        }
        else
        {
            multimap<int, int> cnt;
            for (auto el: mp)
            {
                cnt.emplace(el.second, el.first);
            }
            
            multimap<int, int>::reverse_iterator it1 = cnt.rbegin(), it2 = cnt.rbegin();
            int mn, mx;
            while (it1 != cnt.rend())
            {
                it2 = it1;
                ++it2;

                bool flag = false;

                // cout << it1->first << ' ' << it1->second << endl;
                for (; it2 != cnt.rend(); ++it2)
                {
                    // cout << it2->first << ' ' << it2->second << endl;
                    if ((it1->second + it2->second) % m == 0)
                    {
                        if (it1->first - it2->first > 1)
                        {
                            cnt.emplace(it1->first - it2->first - 1, it1->second);
                        }
                        cnt.erase( next(it2).base() );
                        cnt.erase( next(it1).base() );

                        ++ans;
                        flag = true;
                        break;
                    }
                }

                if (it2 == cnt.rend() && !flag)
                {
                    ++it1;
                }
                else 
                {
                    it1 = cnt.rbegin();
                }
            }
            if (!cnt.empty())
                ans += cnt.size();
        }

        cout << ans << endl;
    }

    return 0;
}
