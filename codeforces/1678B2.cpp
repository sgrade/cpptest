// B2. Tokitsukaze and Good 01-String (hard version)
// Wrong answer on pretest 2

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        string s;
        cin >> s;

        int ops = 0;
        int segs = 1;

        vector<int> v, ss(n);
        int len = 0;

        v.push_back(-1);
        for (int i = 1; i < n; i += 2) {

            if (s[i] == s[i-1]) {
                ++len;
                v.push_back(len);
                ss[i-1] = s[i-1] - 48;
                ss[i] = s[i] - 48;
                continue;
            }

            else {
                len = 0;
                ++ops;
                v.push_back(0);
                ss[i-1] = -1;
                ss[i] = -1;
            }
        }
        v.push_back(-1);

        int idx;
        for (int i = v.size()-2; i > 0; --i) {

            if (v[i] == 0) {

                if (v[i-1] > v[i+1]) {
                    v[i] = v[i-1] + 1;
                    idx = (i-2) * 2;
                    ss[idx + 2] = ss[idx];
                    ss[idx + 3] = ss[idx];
                }

                else if (v[i-1] < v[i+1]) {
                    v[i] = v[i+1] + 1;
                    idx = (i) * 2;
                    ss[idx - 2] = ss[idx];
                    ss[idx - 1] = ss[idx];
                }

                else {
                    if (v[i-1] == -1) {
                        v[i] = 1;
                        ss[0] = 0;
                        ss[1] = 0;
                    }
                    else {
                        v[i] = v[i-1] + 1;
                        idx = idx = (i-1) * 2;
                        ss[idx + 2] = ss[idx];
                        ss[idx + 3] = ss[idx];
                    }
                }
            }

            v[i] = max(v[i], v[i+1]);
        }

        // Count segments
        for (int i = 2; i < n; i += 2) {
            if (ss[i] != ss[i-2]) {
                ++segs;
            }
        }

        cout << ops << ' ' << segs << '\n';
    }

    return 0;
}
