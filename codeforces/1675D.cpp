// D. Vertical Paths

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        
        int n;
        cin >> n;

        vector<int> p(n + 1);
        for (int i = 1; i < n + 1; ++i) {
            cin >> p[i];
        }

        // Editorial - https://codeforces.com/blog/entry/102550

        vector<bool> leaves(n + 1, true);
        
        for (int i = 1; i < n + 1; ++i) {
            leaves[p[i]] = false;
        }

        int ans = 1;

        // Visited
        vector<bool> v(n + 1);

        vector<vector<int>> output;

        if (n > 1) {
            for (int i = 1; i < n + 1; ++i) {
                if (!leaves[i]) continue;

                vector<int> tmp;
                int x = i;
                while (!v[x]) {
                    v[x] = true;
                    tmp.push_back(x);
                    x = p[x];
                }

                output.push_back(tmp);
            }
        }

        else {
            output.push_back({1});
        }

        cout << output.size() << '\n';
        for (int i = 0; i < output.size(); ++i) {
            cout << output[i].size() << '\n';
            for (int j = output[i].size() - 1; j >=0; --j) {
                cout << output[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }

    return 0;
}
