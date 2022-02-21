// C. Differential Sorting
// Wrong answer on test 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n); 
        vector<pair<int, int>> pos;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] >= 0) {
                pos.push_back(pair<int, int>(a[i], i));
            }
        }

        int ans = 0;
        vector<vector<int>> output;

        int x, y, z;
        int j = 0;
        for (x = 0; x < n-2; ++x) {
            if (a[x+1] < a[x]) {
                bool found = false;
                for (y = x+1; !found && y < n-1; ++y) {
                    bool found_z = false;
                    for (; j < size(pos); ++j) {
                        z = pos[j].second;
                        if (z > y) {
                            found_z = true;
                            break;
                        }
                    }
                    if (found_z) {
                        for (; z < n; ++z) {
                            if (a[y] - a[z] <= a[x+1]) {
                                found = true;
                                ++ans;
                                vector<int> tmp = {x, y, z};
                                a[x] = a[y] - a[z];
                                output.push_back(tmp);
                                break;
                            }
                        }
                    }
                    else {
                        ans = -1;
                        break;
                    }
                }

                if (!found) {
                    ans = -1;
                    break;
                }
            }
        }

        // Check the rest
        if (ans != -1) {
            for (int i = n-2; i < n; ++i) {
                if (a[i] < a[i-1]) {
                    ans = -1;
                }
            }
        }

        cout << ans << '\n';
        if (ans != -1) {
            for (auto &v: output) {
                cout << v[0] + 1 << ' ' << v[1] + 1 << ' ' << v[2] + 1 << '\n';
            }
        }

    }

    return 0;
}
