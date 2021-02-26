// B. Phoenix and Beauty

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) 
    {
        int n, k;
        cin >> n >> k;

        int tmp;
        set<int> st;
        for (int i = 0; i < n; ++i) 
        {
            cin >> tmp;
            st.insert(tmp);
        }

        if (st.size() <= k)
        {
            cout << n * k << endl;
            for (int i = 0; i < n; ++i) {
                for (auto el: st) cout << el << ' ';
                for (int i = 0; i < k - st.size(); ++i) cout << "1 ";
            }
            cout << endl;
        }

        else {
            cout << "-1\n";
        }
    }

    return 0;
}
