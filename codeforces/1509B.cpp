// B. TMT Document

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        getline(cin >> ws, s);

        bool ans = true;
        
        if (n % 3 == 0) {

            set<int> t, m;
            for (int i = 0; i < n; ++i) {
                if (s[i] == 'T') {
                    t.insert(i);
                }
                else {
                    m.insert(i);
                }
            }
            
            if (m.size() * 2 == t.size()) {
                set<int>::iterator it_t_front = t.begin(), it_t_back = t.begin();
                for (int i = 0; i < m.size(); ++i) {
                    ++it_t_back;
                }
                for (auto &ind_m: m) {
                    if (*it_t_front < ind_m && ind_m < *it_t_back) {
                        ++it_t_front;
                        ++it_t_back;
                    }
                    else {
                        ans = false;
                        break;
                    }
                }
            }
            else {
                ans = false;
            }
        }

        else {
            ans = false;
        }

        cout << (ans ? "YES" : "NO") << endl;
    }

    return 0;
}
