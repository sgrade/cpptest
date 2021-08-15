// B. Mocha and Red and Blue

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        string s;
        getline(cin >> ws, s);

        vector<char> v(begin(s), end(s));
        for (int i = 0; i < n; ++i) {
            auto it = find_if_not(begin(v), end(v), [](char ch){
                return ch == '?';
            });
            int idx = distance(begin(v), it);

            vector<char> nxt = {'B', 'R'};
            int flag;
            int j;
            char ch = v[idx];

            if (it != end(v)) {
                flag = ch == 'B' ? 1 : 0;
                for (j = idx - 1; j >=0; --j) {
                    if (v[j] != '?') break;
                    v[j] = nxt[flag];
                    flag = !flag;
                }
            }
            else {
                v[0] = 'B';
                j = 1;
            }

            while(true) {
                it = find(begin(v) + j, end(v), '?');
                if (it == end(v)) break;

                j = distance(begin(v), it);
                flag = v[j-1] == 'B' ? 1 : 0;

                for (; j < n; ++j) {
                    if (v[j] != '?') break;
                    v[j] = nxt[flag];
                    flag = !flag;
                }
            }
        }

        for (auto &ch: v) {
            cout << ch;
        }
        cout << endl;
    }

    return 0;
}
