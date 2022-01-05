// B. Game on Ranges

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    // Editorial - https://codeforces.com/blog/entry/98463

    while (t--) {
        
        int n;
        cin >> n;


        set<pair<int, int>> st;
        pair<int, int> tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp.first >> tmp.second;
            st.insert(tmp);
        }

        set<int> d_set;
        for (int i = 1; i <=n; ++i) {
            d_set.insert(i);
        }

        set<int>::iterator d = begin(d_set);
        while(true) {
            
            int cnt = 0;
            for (auto &p: st) {
                if (p.first <= *d && *d <= p.second) {
                    ++cnt;
                    if (cnt > 1) {
                        break;
                    }
                    tmp.first = p.first;
                    tmp.second = p.second;
                }
            }

            if (cnt == 1) {
                cout << tmp.first << ' ' << tmp.second << ' ' << *d << '\n';
                st.erase(pair<int, int>(tmp.first, tmp.second));
                d_set.erase(d);
                if (size(d_set) > 0) {
                    d = begin(d_set);
                }
                else {
                    break;
                }
            }
            else {
                ++d;
            }
        }
        cout << '\n';
    }

    return 0;
}
